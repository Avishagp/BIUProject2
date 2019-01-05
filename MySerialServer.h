
#ifndef BIUPROJECT2_MYSERIALSERVER_H
#define BIUPROJECT2_MYSERIALSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <vector>
#include <thread>
#include <sstream>
#include "Server.h"
#include "ClientHandler.h"

using namespace server_side;

class MySerialServer : public Server {

public:
    virtual void open(int port, ClientHandler* clientHandler);
    virtual void stop();
};


#endif //BIUPROJECT2_MYSERIALSERVER_H
