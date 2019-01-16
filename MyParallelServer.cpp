
#include "MyParallelServer.h"

/**
 * Create and open the server, for each accepted client we open a thread.
 * We stop accepting after a timeout event, in this case we call stop function.
 * @param port The port to listen on.
 * @param clientHandler The client handler to use for each client.
 */
void MyParallelServer::open(int port, ClientHandler *clientHandler) {

    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    bool first_client_served = false;

    /**
     * First call to socket() function:
     * AF_INET     - IPv4 (Domain protocol)
     * SOCK_STREAM - TCP (Communication type)
     * 0           - IP (Protocol)
     */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Initialize and set thread as joinable. */
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* Check of creation succeeded*/
    if (sockfd < 0) {
        //perror("Error opening socket.");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)port));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //perror("Failed to bind server connection.");
        exit(1);
    }

    bool time_out = false;

    /* Now start listening for the clients. */
    while (!time_out) {

        /* Waiting forever for first client only. */
        if (first_client_served) {
            timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;

            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        }

        listen(sockfd,5);
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        /* Flag we got at least one client served. */
        first_client_served = true;

        /* Checking connection success. */
        if (newsockfd < 0) {
            //perror("timeout!");
            time_out = true;
        } else {

            /* If we got a connected client, call handler in new thread. */
            auto args = new ArgumentsForOpenServer(port, clientHandler, newsockfd);
            pthread_t* pthread = new pthread_t;
            this->threads.push_back(pthread);
            pthread_create(pthread, &attr, MyParallelServer::callHandler ,(void*)(args));
        }
    }

    /* Free attribute */
    pthread_attr_destroy(&attr);
    stop();
}

/**
 * Joining all the threads we opened by order and deleting allocated objects.
 */
void MyParallelServer::stop() {

    void* status;
    auto iterator = this->threads.begin();
    for (; iterator != this->threads.end(); ++iterator) {
        pthread_join((*(*iterator)), &status);
        free((*iterator));
    }
}

/**
 * Wrap's the call to client handler.
 * @param args The arguments needed.
 * @return
 */
void *MyParallelServer::callHandler(void* args) {

    /* Call client handler. */
    auto * arguments = (ArgumentsForOpenServer*) args;
    arguments->getClientHandler()->handleClient(arguments->getSocketID());
}
