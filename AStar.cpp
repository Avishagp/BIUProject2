
#include "AStar.h"

template <class P, class S>
int AStar<P,S>::heuristic(ISearchable<P> searchable, State<S> a, State<S> b) {
    return searchable.getDistance(a, b);
}

template <class P, class S>
S AStar<P,S>::searchInPossibleStates(ISearchable<P> searchable, State<S> *initial, State<S> *goal) {
    std::priority_queue<State<S>> pq;
    pq.push(initial);
    initial->setVisited(true);
    State<S> node;

    while (!pq.empty()) {
        node = pq.front();
        pq.pop(); //delete the element we have just gotten.
        this->numberOfNodesEvaluated++;
        /* Set the cost of the node. */
        node.setCost(node.getCost() + node.getCameFrom()->getCost());

        if (node.Equals(goal)) {
            return goal->getState();
        }

        /* Iterate on all of node's children. */
        std::vector<State<S>> possibles = searchable.getAllPossibleStates(node);
        typename std::vector<State<S>>::iterator itor;

        for (itor = possibles.begin(); itor != possibles.end(); itor++) {
            int newCost = itor->getCost() + node.getCost();
        }

    }
}

template <class P, class S>
S AStar<P,S>::search(ISearchable<P> searchable) {

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
    return nullptr;
}