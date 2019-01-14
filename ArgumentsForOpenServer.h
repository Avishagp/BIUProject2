
#ifndef BIUPROJECT2_ARGUMENTSFOROPENSERVER_H
#define BIUPROJECT2_ARGUMENTSFOROPENSERVER_H

#include "ClientHandler.h"

/**
 * Used to send arguments for threads.
 */
class ArgumentsForOpenServer {
private:
    ClientHandler *clientHandler;
    int portNum;
    int socketID;
public:

    /* Constructors. */
    ArgumentsForOpenServer(int portNum1, ClientHandler *clientHandler1) {
        clientHandler = clientHandler1;
        portNum = portNum1;
        this->socketID = 0;
    }

    ArgumentsForOpenServer(int portNum1, ClientHandler *clientHandler1, int socket) {
        clientHandler = clientHandler1;
        portNum = portNum1;
        this->socketID = socket;
    }

    /* Getters. */
    int getPortNum() {
        return this->portNum;
    }

    ClientHandler* getClientHandler() {
        return this->clientHandler;
    }

    int getSocketID() const {
        return socketID;
    }
};


#endif //BIUPROJECT2_ARGUMENTSFOROPENSERVER_H
