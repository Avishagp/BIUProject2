
#ifndef BIUPROJECT2_ASTAR_H
#define BIUPROJECT2_ASTAR_H

#include <vector>
#include <string>
#include <queue>
#include <map>
#include "PQSearcher.h"
#include "State.h"
#include "BestFirstSearch.h"

template <class P, class S>

class AStar  : public BestFirstSearch<P,S> {
private:
    int heuristic(State<P>* a, State<P>* b) {
        int x1 = a->getState().first;
        int y1 = a->getState().second;
        int x2 = b->getState().first;
        int y2 = b->getState().second;

        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    double CalcuatePotentialCost(typename std::vector<State<P>*>::iterator it, State<P>* current) override {
        return (*it)->getCost() + current->getCost() + heuristic((*it), current);
    }
};


#endif //BIUPROJECT2_ASTAR_H
