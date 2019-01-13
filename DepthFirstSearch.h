
#ifndef BIUPROJECT2_DFS_H
#define BIUPROJECT2_DFS_H

#include <vector>
#include <string>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class DepthFirstSearch : public ISearcher<P,S> {
public:
    S search(ISearchable<P>* searchable) override {
        /* Get the initial state and the goal state from the searchable. */
        State<S> *current = searchable->getInitialState();
        State<S> *goal = searchable->getGoalState();

        typename std::vector<State<S>>::iterator itor;
        std::vector<State<S>> possible = searchable->getAllPossibleStates(current);

        /* Iterate on all the possible states. */
        for (itor = possible.begin(); itor != possible.end(); itor++) {
            /* Set the node that we came from. */
            itor->setCameFrom(current);

            if (itor->getVisited()) { //node has already been visited.
                continue;
            } else {
                itor->setState(true); //set visited
                this->numberOfNodesEvaluated++; //increment number of nodes visited

                if (itor->Equals(goal)) { //If current state is the goal, return.
                    return goal->getState();
                } else {
                    /* Search all sons of itor. If one of them is goal, return it! */
                    if (searchInPossibleStates(searchable, &itor, goal) == goal->getState()) {
                        return goal->getState();
                    }
                }
            }
        }
        return current->getState(); //all sons weren't goal
    }
};


#endif //BIUPROJECT2_DFS_H
