
#ifndef BIUPROJECT2_MYSERIALSERVER_H
#define BIUPROJECT2_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

using namespace server_side;

class MySerialServer : public Server {

public:
    virtual void open(int port, ClientHandler clientHandler);
    virtual void stop();
};


#endif //BIUPROJECT2_MYSERIALSERVER_H
