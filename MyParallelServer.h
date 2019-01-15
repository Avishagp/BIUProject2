
#ifndef BIUPROJECT2_MYPARALLELSERVER_H
#define BIUPROJECT2_MYPARALLELSERVER_H

#include <pthread.h>
#include <string.h>
#include <string>
#include <vector>
#include <thread>
#include <sstream>
#include <mutex>
#include "Server.h"
#include "ClientHandler.h"
#include "ArgumentsForOpenServer.h"

using namespace server_side;
static std::mutex mutexxxx;
//extern pthread_mutex_t global_mutex;

class MyParallelServer : public Server {
private:
    /* Holds all the opened pthreads. */
    std::vector<pthread_t*> threads;

public:
    void open(int port, ClientHandler *clientHandler) override;
    void stop() override;

private:
    static void* callHandler(void*);
};


#endif //BIUPROJECT2_MYPARALLELSERVER_H
