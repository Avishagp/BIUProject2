
#ifndef BIUPROJECT2_ASTAR_H
#define BIUPROJECT2_ASTAR_H

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <math.h>
#include "PQSearcher.h"
#include "State.h"
#include "BestFirstSearch.h"

template <class P, class S>
class AStar  : public BestFirstSearch<P,S> {

private:

    /**
    * Calculate the linear distance between two States.
    * @param a First State.
    * @param b Second State.
    * @return The linear distance between two States.
    */
    double heuristic(State<P>* a, State<P>* b) {
        int x1 = a->getState().first;
        int y1 = a->getState().second;
        int x2 = b->getState().first;
        int y2 = b->getState().second;

        double power1 = pow(x2-x1,2);
        double power2 = pow(y2-y1,2);
        return sqrt(power1 + power2);
    }

public:

    double CalculatePotentialCost(typename std::vector<State<P>*>::iterator it, State<P>* current, State<P>* goal) override {
        if ((*it)->getCameFrom() == NULL) {
            return ((*it)->getCost() + heuristic((*it), goal));
        }
        return ((*it)->getCost() + current->getCost() + heuristic((*it), goal) - heuristic(current, goal));
    }
};


#endif //BIUPROJECT2_ASTAR_H
