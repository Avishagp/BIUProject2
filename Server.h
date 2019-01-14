
#ifndef BIUPROJECT2_SERVER_H
#define BIUPROJECT2_SERVER_H

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include "ClientHandler.h"

/**
 * Define's a serve.
 */
namespace server_side {
    class Server {
    public:

        /**
         * Open's the server in a specific port and calls a handler.
         * @param port The port to use.
         * @param clientHandler The handler to use.
         */
        virtual void open(int port, ClientHandler* clientHandler) = 0;

        /**
         * Stop's the server.
         */
        virtual void stop() = 0;
    };
}


#endif //BIUPROJECT2_SERVER_H
