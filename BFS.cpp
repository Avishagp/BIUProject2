
#include "BFS.h"

template <class P, class S>
S BFS<P,S>::searchInAllPossibleStates(ISearchable<P> searchable, State<S> *initial, State<S> *goal) {
    std::queue<State<S>> qs;
    qs.push(initial);
    initial->setVisited(true);
    State<S> node;

    /* Loop on every node. */
    while (!qs.empty()) {
        node = qs.front();
        qs.pop(); //delete the element we have just gotten.
        this->numberOfNodesEvaluated++;

        if (node.Equals(goal)) {
            return goal->getState();
        }

        /* Iterate on all of node's children. */
        std::vector<State<S>> possibles = searchable.getAllPossibleStates(node);
        typename std::vector<State<S>>::iterator itor;

        for (itor = possibles.begin(); itor != possibles.end(); itor++) {
            /* If a child node wasn't visited, add to queue. */
            if (!itor->getVisited()) {
                itor->setVisited(true);
                qs.push(itor);
                itor->setCameFrom(node);
            }
        }
    }
    return node.getState(); //all sons weren't goal.
}

template <class P, class S>
S BFS<P,S>::search(ISearchable<P> searchable) {

    /* Get the initial state and the goal state from the searchable. */
    State<S> *initial = searchable.getInitialState();
    State<S> *goal = searchable.getGoalState();

    /* Call search function in order to search searchable. */
    S wasGoalFound = searchInAllPossibleStates(searchable, initial, goal);

    //TODO: CHECK HOW WE GOT TO GOAL


}