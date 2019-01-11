
#ifndef BIUPROJECT2_BESTFIRSTSEARCH_H
#define BIUPROJECT2_BESTFIRSTSEARCH_H

#include <algorithm>
#include "PQSearcher.h"

template <class P, class S>
class BestFirstSearch : PQSearcher<P,S> {
private:
public:
    S search(ISearchable<P>* searchable) override {

        /* Closed list */
        std::vector<State<P>> closeSet;
        /* Open list */
        searchable->getInitialState()->setVisited(true);
        //searchable->getInitialState()->setCost(searchable->)
        this->stateSet.insert(searchable->getInitialState());
        this->numberOfNodesEvaluated++;

        /* Bode iterator. */
        State<P>* current = nullptr;


        while (!this->stateSet.empty()) {

            /* Remove best node from Open and save it to closed. */
            current = this->stateSet.lower_bound();
            /* Update state. */
            if (!current->getVisited()) {
                current->setVisited(true);
                this->numberOfNodesEvaluated++;
            }
            this->stateSet.erase(current);
            closeSet.push_back(current);

            /* If we got to goal, stop. */
            if (current->Equals(searchable->getGoalState())) {
                //TODO Backtrack to get path and return.
            }

            /* Get all successors. */
            std::vector<State<P>*> successors = searchable->getAllPossibleStates(current);

            typename std::vector<State<P>*>::iterator it;
            it = successors.begin();
            for (; it != successors.end(); ++it) {

                /* Check if successor is in closed/open vectors. */
                State<P>* is_in_open   = std::find(closeSet.begin(), closeSet.end(), (*it));
                State<P>* is_in_closed = this->stateSet.find((*it));
                if ((is_in_open == closeSet.end()) && (is_in_closed == this->stateSet.end() )) {
                    /* successor is not in closed and open vector. */

                    /* Update State and add to open. */
                    (*it)->setCameFrom(current);
                    this->stateSet.insert((*it));

                } else {
                    /* successor is in closed or open vector. */

                    /* Check if this new path is better than previous one. */
                    double  it_cost = (*it)->getCost();
                    if ( false | true ) {

                    } else {

                    }
                }

            }

        }

    }
};


#endif //BIUPROJECT2_BESTFIRSTSEARCH_H
