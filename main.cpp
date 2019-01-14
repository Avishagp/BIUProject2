
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "AStar.h"
int heuristicCheck(State<std::pair<int,int>>* a, State<std::pair<int,int>>* b) {
    int x1 = a->getState().first;
    int y1 = a->getState().second;
    int x2 = b->getState().first;
    int y2 = b->getState().second;

    return abs(x1 - x2) + abs(y1 - y2);
}
int main() {

    ISearchable<std::pair<int,int>>* a = new SearchableMatrix(" 0, 1, 6, 2, 8, 2, 9, 4, 8, 7, 5, 9, 8, 0, 1, 3, 6\n"
                                                              " 4, 1, 0, 9,10, 0, 7, 9, 0, 1, 2, 8, 9, 3,10, 6, 7\n"
                                                              " 1, 7, 8, 9, 1, 0, 1,10,10, 0,10, 1, 0,10, 3, 7, 5\n"
                                                              " 0, 7, 6, 9,10, 5,10, 6, 3, 8, 0, 7, 9, 7, 1, 7, 1\n"
                                                              " 9, 1, 3, 5, 6, 0,10, 4, 1, 7, 4, 6, 6, 2, 8,10, 5\n"
                                                              " 2, 2, 1, 1, 6, 0, 6, 4, 9, 5, 6,10, 7, 3, 3,10, 5\n"
                                                              " 3, 0, 3,10, 1, 8,10, 4, 9, 4, 9, 0, 3, 1, 0, 3, 8\n"
                                                              " 4, 1, 4, 8, 9, 1, 9, 3, 7, 8, 5, 0, 5, 1, 4, 4, 0\n"
                                                              "-1, 3, 9, 5, 5,10, 2, 3, 2, 8,10, 3, 5, 8, 6, 3, 2\n"
                                                              " 1, 4, 8,10, 9, 6, 0, 4, 0, 0, 5, 2,10, 3, 6, 8, 4\n"
                                                              " 0, 6, 2, 7, 1, 6, 4, 3, 4, 7, 6, 2, 7, 0, 5,10, 1\n"
                                                              " 9, 3, 0, 8, 8, 6, 7, 8, 0, 0, 1, 6, 3, 6, 4, 6, 9\n"
                                                              " 9, 6, 3, 6, 7, 3, 9, 5,10, 6, 7, 1, 3, 6, 9,10, 2\n"
                                                              " 7, 4, 3, 5, 4, 3, 6, 6, 6, 7, 2, 8, 4, 1, 6, 8, 0\n"
                                                              " 1, 2, 1, 2, 5, 2, 7, 0, 9, 3, 3, 4,10, 2, 1, 7, 9\n"
                                                              " 6, 5, 0, 3, 4,10, 3, 3, 0, 0, 5, 8, 0, 1, 9, 0, 9\n"
                                                              " 3, 2, 2, 3, 0, 4, 9, 3, 5, 3, 6, 5, 8, 4, 7, 6, 7");
    ISearcher<std::pair<int,int>,State<std::pair<int,int>>*>* s = new AStar<std::pair<int,int>,State<std::pair<int,int>>*> ();
    //DepthFirstSearch<std::pair<int,int>,State<std::pair<int,int>>*>* s = new DepthFirstSearch<std::pair<int,int>,State<std::pair<int,int>>*> ();
    //BreadthFirstSearch<std::pair<int,int>,State<std::pair<int,int>>*>* s = new BreadthFirstSearch<std::pair<int,int>,State<std::pair<int,int>>*> ();
    State<std::pair<int,int>>* pathEnd = s->search(a);

    State<std::pair<int,int>>* current  = pathEnd;
    State<std::pair<int,int>>* previous = current->getCameFrom();
    std::string result;
    double finalCost = pathEnd->getCost();

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

        finalCost -= heuristicCheck(current, previous);

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
