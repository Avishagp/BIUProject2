
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "DepthFirstSearch.h"

int main() {

    ISearchable<std::pair<int,int>>* a = new SearchableMatrix("1,1,1,-1,-1\n-1,-1,1,-1,-1\n1,1,1,-1,-1\n1,-1,-1,-1,-1\n1,1,1,1,1");
    ISearcher<std::pair<int,int>,State<std::pair<int,int>>*>* s = new DepthFirstSearch<std::pair<int,int>,State<std::pair<int,int>>*> ();
    State<std::pair<int,int>>* pathEnd = s->search(a);

    State<std::pair<int,int>>* current  = pathEnd;
    State<std::pair<int,int>>* previous = current->getCameFrom();
    std::string result;

    while (previous != nullptr) {

        std::pair<int,int> current_pos  = current->getState();
        std::pair<int,int> previous_pos = previous->getState();

        /* Check movement UP */
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


    delete(a);

    FileCacheManager fileCacheManager("bla.txt");
    StringReverser stringReverser;
    MyTestClientHandler myTestClientHandler(&stringReverser, &fileCacheManager);
    MySerialServer mySerialServer;
    mySerialServer.open(5400, &myTestClientHandler);
    while (true) {};
}
