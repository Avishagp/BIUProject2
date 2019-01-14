
#include <iostream>
#include <pthread.h>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "DepthFirstSearch.h"
#include "SolverToSearcherAdapter.h"

pthread_mutex_t mutex;

int main() {

    //pthread_mutex_lock(&mutex);
    //pthread_mutex_unlock(&mutex);

    /*
     * State<std::pair<int,int>>* pathEnd = searcher->search(searchable);

        State<std::pair<int,int>>* current = pathEnd;
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
     */

    Solver<ISearchable<std::pair<int, int>> *,State<std::pair<int, int>> *> *solver
        = new  SolverToSearcherAdapter(nullptr);

    CacheManager* cacheManager = new FileCacheManager("test.txt");
    MyClientHandler myClientHandler(solver, cacheManager);

    MyParallelServer myParallelServer;
    myParallelServer.open(5400, &myClientHandler);

    while (true) {};

    pthread_mutex_destroy(&mutex);
}
