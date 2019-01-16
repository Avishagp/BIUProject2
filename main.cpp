
#include <iostream>
#include <pthread.h>
#include <mutex>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "DepthFirstSearch.h"
#include "SolverToSearcherAdapter.h"

std::string GetPath(State<std::pair<int,int>>* go) {

    State<std::pair<int,int>>* current = go;
    State<std::pair<int,int>>* previous = current->getCameFrom();
    std::string result;
    while (previous != nullptr) {
        std::pair<int,int> current_pos  = current->getState();
        std::pair<int,int> previous_pos = previous->getState();
        if (current_pos.first == previous_pos.first + 1 ) {
            result.insert(0, ",down");
        } else if (current_pos.first == previous_pos.first - 1) {
            result.insert(0, ",up");
        } else if (current_pos.second == previous_pos.second - 1) {
            result.insert(0, ",left");
        } else if (current_pos.second == previous_pos.second + 1) {
            result.insert(0, ",right");
        }
        current  = previous;
        previous = current->getCameFrom();
    }
    result.erase(0,1);

    return result;

}

int main(int argc, char** argv) {

    /* Trying to get port from client. */
    int port;
    if (argc == 1) {
        //perror("No port provided.\n");
        exit(0);
    } else if (argc == 2) {
        try {
            port = std::stoi(argv[1]);
        } catch (std::exception &e) {
            //perror("Bad port provided.\n");
            exit(0);
        }
    } else {
        //perror("To many arguments provided.\n");
        exit(0);
    }

    /* Creates searcher as a solver. */
    ISearcher<std::pair<int, int> , State<std::pair<int,int>>*>* searcher;
    searcher = new BestFirstSearch<std::pair<int, int> , State<std::pair<int,int>>*>;
    Solver<ISearchable<std::pair<int, int>> *,State<std::pair<int, int>> *> *solver
        = new  SolverToSearcherAdapter(searcher);

    /* Creates CacheManager and ClientHandler. */
    CacheManager* cacheManager = new FileCacheManager("matrix.txt");
    MyClientHandler myClientHandler(solver, cacheManager);

    /* Create and call server. */
    MyParallelServer myParallelServer;
    myParallelServer.open(port, &myClientHandler);

    /* Delete used space. */
    delete(searcher);
    delete(solver);
    delete(cacheManager);

};
