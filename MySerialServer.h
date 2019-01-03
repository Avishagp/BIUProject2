
#ifndef BIUPROJECT2_MYSERIALSERVER_H
#define BIUPROJECT2_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

using namespace server_side;

class MySerialServer : public Server {
public:
    void open(int port, ClientHandler clientHandler) override;
    void stop() override;
};


#endif //BIUPROJECT2_MYSERIALSERVER_H
