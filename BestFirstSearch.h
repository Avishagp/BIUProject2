
#ifndef BIUPROJECT2_BESTFIRSTSEARCH_H
#define BIUPROJECT2_BESTFIRSTSEARCH_H

#include <algorithm>
#include <map>
#include "PQSearcher.h"

template <class P, class S>
class BestFirstSearch : public PQSearcher<P,S> {
private:

public:

    /**
     * Constructor, Defines the compare method of the multiset in PQSearcher.
     */
    BestFirstSearch() : PQSearcher <P,S> (BestFirstSearch::Compare){}

    /**
     * The compare method of the multiset in PQSearcher.
     * @param a First  object.
     * @param b Second object.
     * @return (a < b)
     */
    static bool Compare (State<P>* a, State<P>* b) {
        return a->getCost() < b->getCost();
    }

    /**
     * Searches using the Best First Search algorithm.
     * @param searchable The object to search in.
     * @return Solution.
     */
    S search(ISearchable<P>* searchable) override {

        /* Closed list */
        std::vector<State<P>*> closeSet;
        std::map<State<P>*,int> closeMap;

        /* Open list */
        searchable->getInitialState()->setVisited(true);
        this->stateSet.insert(searchable->getInitialState());

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
            this->numberOfNodesEvaluated++;
            closeMap.insert({current,0});

            /* If we got to goal, stop. */
            if (current->Equals(searchable->getGoalState())) {
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
                    (*it)->setCameFrom(current);
                    (*it)->setDistance_from_start(current->getDistance_from_start() + 1);
                    (*it)->setTotal_cost_to((*it)->getOriginal_cost() + current->getTotal_cost_to());
                    (*it)->setVisited(true);
                    (*it)->setCost(CalculatePotentialCost((*it),current ,searchable->getGoalState(), searchable->getInitialState()));
                    this->stateSet.insert((*it));

                } else {
                    /* successor is in closed or open vector. */

                    /* Check if this new path is better than previous one. */
                    double it_actual_cost    = (*it)->getCost() ;//- (*it)->getCameFrom()->getCost();
                    double it_potential_cost = CalculatePotentialCost((*it), current, searchable->getGoalState(), searchable->getInitialState());

                    if ( it_potential_cost < it_actual_cost ) {

                        if (is_in_map == 0) {
                            closeMap.erase((*it));
                        }

                        /* If it is in open, remove it. */
                        if (is_in_open != this->stateSet.end()) {
                            this->deleteInSet((*it));
                        }

                        /* Update stats and add to openSet. */
                        (*it)->setCameFrom(current);
                        (*it)->setDistance_from_start(current->getDistance_from_start() + 1);
                        (*it)->setTotal_cost_to((*it)->getOriginal_cost() + current->getTotal_cost_to());
                        (*it)->setCost(it_potential_cost);
                        this->stateSet.insert((*it));

                    }
                }
            }
        }
        return nullptr;
    }

    /**
     * Calculate the potential cost of a path.
     * @param it - Iterator to the next step.
     * @param current - The current State.
     * @param goal - The goal State.
     * @return The combined cost of the States.
     */
    virtual double CalculatePotentialCost(State<P>* current, State<P>* papa, State<P>* goal, State<P>* start) {
        return current->getCost() + papa->getCost();
    }

};


#endif //BIUPROJECT2_BESTFIRSTSEARCH_H
