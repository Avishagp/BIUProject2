
#include "DepthFirstSearch.h"

template <class P, class S>
S DepthFirstSearch<P,S>::searchInPossibleStates(ISearchable<P> searchable, State<S> *current, State<S> *goal) {
    typename std::vector<State<S>>::iterator itor;
    std::vector<State<S>> possible = searchable.getAllPossibleStates(current);

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

template <class P, class S>
S DepthFirstSearch<P,S>::search(ISearchable<P> searchable) {
    /* Get the initial state and the goal state from the searchable. */
    State<S> *initial = searchable.getInitialState();
    State<S> *goal = searchable.getGoalState();

    /* If initial is not goal, go in recursive function and start checking it's possible states (adjacency). */
    if (initial->Equals(goal)) {
        return initial->getState();
    }
    S wasGoalFound = searchInPossibleStates(searchable, initial, goal);

    ///* Check how we got to goal. */
    //if (wasGoalFound == goal->getState()) {
    //    std::string route;
    //    State<S> current = goal;
    //    while (current != initial) {
    //        State<S> cameFrom = current.getCameFrom();
//TODO
    //    }
    //}

}