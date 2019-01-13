
#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *clientHandler) {

    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

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
        perror("Error opening socket.");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)port));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind server connection.");
        exit(1);
    }

    bool time_out = false;
    /* Now start listening for the clients. */
    while (!time_out) {
        listen(sockfd,5);
        clilen = sizeof(cli_addr);

        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("timeout!");
            time_out = true;
        } else {

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

void MyParallelServer::stop() {

    void* status;
    auto iterator = this->threads.begin();
    for (; iterator != this->threads.end(); ++iterator) {
        pthread_join((*(*iterator)), &status);
        free((*iterator));
    }

    this->threads.clear();

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
