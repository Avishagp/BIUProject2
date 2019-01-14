
#ifndef BIUPROJECT2_MYTESTCLIENTHANDLER_H
#define BIUPROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <string>
#include <sstream>
#include <strings.h>
#include <unistd.h>

using namespace std;

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string, string> *solver;
    CacheManager *cacheManager;

public:

    MyTestClientHandler(Solver<string, string> *solver1, CacheManager *cacheManager1) {
        solver = solver1;
        cacheManager = cacheManager1;
    }

    void handleClient(int socketfd) override;
};


#endif //BIUPROJECT2_MYTESTCLIENTHANDLER_H
