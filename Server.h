
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

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* clientHandler) = 0;
        virtual void stop() = 0;
    };
}


#endif //BIUPROJECT2_SERVER_H
