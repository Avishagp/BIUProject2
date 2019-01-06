
#include "MySerialServer.h"

void* MySerialServer::openServer(void* portNum) {
    int* port = (int*)portNum;

    int sockfd, newsockfd, clilen;

    struct sockaddr_in serv_addr, cli_addr;

    /**
     * First call to socket() function:
     * AF_INET     - IPv4 (Domain protocol)
     * SOCK_STREAM - TCP (Communication type)
     * 0           - IP (Protocol)
     */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Check of creation succeeded*/
    if (sockfd < 0) {
        perror("Error opening socket.");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)*port));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind server connection.");
        exit(1);
    }

    /* Now start listening for the clients. */

    while (true) {
        listen(sockfd,5);
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        /* If connection is established then start communicating. */


    }

    /* Close socket. */
    close(newsockfd);
}

void MySerialServer::open(int port, ClientHandler clientHandler) {

    /* Create thread that'll open a server and read from the client. */
    pthread_t pthread;
    pthread_create(&pthread, nullptr, MySerialServer::openServer, (void*)(&port));

}

void MySerialServer::stop() {

}