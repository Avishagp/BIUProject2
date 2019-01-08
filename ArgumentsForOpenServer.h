
#ifndef BIUPROJECT2_ARGUMENTSFOROPENSERVER_H
#define BIUPROJECT2_ARGUMENTSFOROPENSERVER_H

#include "ClientHandler.h"

class ArgumentsForOpenServer {
private:
    ClientHandler *clientHandler;
    int portNum;
public:
    ArgumentsForOpenServer(int portNum1, ClientHandler *clientHandler1) {
        clientHandler = clientHandler1;
        portNum = portNum1;
    }
    int getPortNum() {
        return this->portNum;
    }
    ClientHandler* getClientHandler() {
        return this->clientHandler;
    }
};


#endif //BIUPROJECT2_ARGUMENTSFOROPENSERVER_H
