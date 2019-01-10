
#include "DFS.h"

template <class P, class S>
S DFS<P,S>::searchInPossibleStates(ISearchable<P> searchable, std::vector<State<S>> possible, State<S> goal) {
    typename std::vector<State<S>>::iterator itor;

    /* Iterate on all the possible states. */
    for (itor = possible.begin(); itor != possible.end(); itor++) {
        if (itor->getVisited()) {
            continue;
        }
        /* If current state is the goal, stop and return. */
        if (itor->Equals(goal)) {
            break;
        } else {
            if (searchInPossibleStates(searchable) == goal.getState()) {
                break;
            }
        }
    }
    return itor->getState();
}

template <class P, class S>
S DFS<P,S>::search(ISearchable<P> searchable) {
    /* Get the initial state and the goal state from the searchable. */
    State<S> initial = searchable.getInitialState();
    State<S> goal = searchable.getGoalState();
    std::vector<State<S>> possible = searchable.getAllPossibleStates(initial);

    /* If initial is not goal, go in recursive function and start checking it's possible states (adjacency). */
    if (initial.Equals(goal)) {
        return initial.getState();
    }
    return searchInPossibleStates(searchable, possible, goal);
}