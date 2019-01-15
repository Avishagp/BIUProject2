
#ifndef BIUPROJECT2_MYCLIENTHANDLER_H
#define BIUPROJECT2_MYCLIENTHANDLER_H

#include <string>
#include <string.h>
#include <thread>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include "Solver.h"
#include "ClientHandler.h"
#include "CacheManager.h"
#include "SearchableMatrix.h"
#include "MyParallelServer.h"

class MyClientHandler : public ClientHandler{
private:
    Solver<ISearchable<std::pair<int,int>>*,State<std::pair<int,int>>*> *solver;
    CacheManager *cacheManager;
    int CountCharsInString(std::string, char);

    std::string GetPath(State<std::pair<int,int>>*);
    std::string Read(int);
    std::size_t GetHashOfString(std::string);
public:

    /* Constructor. */
    MyClientHandler
        (Solver<ISearchable<std::pair<int, int>> *,State<std::pair<int, int>> *> *solver,
         CacheManager *cacheManager) {

        this->cacheManager = cacheManager;
        this->solver = solver;
    }

    void handleClient(int i) override;
};


#endif //BIUPROJECT2_MYCLIENTHANDLER_H
