
#ifndef BIUPROJECT2_BESTFIRSTSEARCH_H
#define BIUPROJECT2_BESTFIRSTSEARCH_H

#include <algorithm>
#include <map>
#include "PQSearcher.h"

template <class P, class S>
class BestFirstSearch : public PQSearcher<P,S> {
private:

public:

    BestFirstSearch() : PQSearcher <P,S> (BestFirstSearch::Compare){}

    static bool Compare (State<P>* a, State<P>* b) {
        return a->getCost() < b->getCost();
    }

    S search(ISearchable<P>* searchable) override {

        /* Closed list */
        std::vector<State<P>*> closeSet;
        std::map<State<P>*,int> closeMap;

        /* Open list */
        searchable->getInitialState()->setVisited(true);
        this->stateSet.insert(searchable->getInitialState());
        this->numberOfNodesEvaluated++;



        /* Bode iterator. */
        State<P>* current = nullptr;

        while (!this->stateSet.empty()) {

            /* Remove best node from Open and save it to closed. */
            current = (*this->stateSet.begin());

            /* Update state. */
            if (!current->getVisited()) {
                current->setVisited(true);
            }
            this->deleteInSet(current);
            closeMap.insert({current,0});
            //closeSet.push_back(current);

            /* If we got to goal, stop. */
            if (current->Equals(searchable->getGoalState())) {
                //TODO Backtrack to get path and return.
                return current;
            }

            /* Get all successors. */
            std::vector<State<P>*> successors = searchable->getAllPossibleStates(current);

            typename std::vector<State<P>*>::iterator it = successors.begin();
            for (; it != successors.end(); ++it) {

                /* Check if successor is in closed/open vectors. */
                int is_in_map = (unsigned int) closeMap.count((*it));
                typename std::set<State<P>*,StateComparatorLesser<P>>::iterator is_in_open = this->findInSet((*it));


                if ((is_in_map == 0 ) && (is_in_open == this->stateSet.end())) {
                    /* successor is not in closed and not in open vector. */

                    /* Update State and add to open. */
                    this->numberOfNodesEvaluated++;
                    (*it)->setCameFrom(current);
                    (*it)->setVisited(true);
                    (*it)->setCost((*it)->getCost() + current->getCost());
                    this->stateSet.insert((*it));

                } else {
                    /* successor is in closed or open vector. */

                    /* Check if this new path is better than previous one. */
                    double it_current_cost   = (*it)->getCost();
                    double it_actual_cost    = it_current_cost - (*it)->getCameFrom()->getCost();
                    double it_potential_cost = it_current_cost + current->getCost();

                    if ( it_potential_cost < it_actual_cost ) {

                        /* If it is in open, remove it. */
                        if (is_in_open != this->stateSet.end()) {
                            this->deleteInSet((*it));
                        }

                        /* Update stats and add to openSet. */
                        (*it)->setCameFrom(current);
                        (*it)->setCost(it_potential_cost);
                        this->stateSet.insert((*it));

                    }
                }

            }

        }
        return "Done";
    }
};


#endif //BIUPROJECT2_BESTFIRSTSEARCH_H
