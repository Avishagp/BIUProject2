
#ifndef BIUPROJECT2_MYTESTCLIENTHANDLER_H
#define BIUPROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver *solver;
    CacheManager *cacheManager;
public:
    MyTestClientHandler(Solver *solver1, CacheManager *cacheManager1) {
        solver = solver1;
        cacheManager = cacheManager1;
    }
    void handleClient(std::stringstream input, std::stringstream output) override;
};


#endif //BIUPROJECT2_MYTESTCLIENTHANDLER_H
