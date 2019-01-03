
#ifndef BIUPROJECT2_SERVER_H
#define BIUPROJECT2_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port,  ClientHandler clientHandler) = 0;
        virtual void stop() = 0;
    };
}


#endif //BIUPROJECT2_SERVER_H
