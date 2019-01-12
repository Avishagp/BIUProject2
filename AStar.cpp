
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

        if (node.Equals(goal)) {
            return goal->getState();
        }

        /* Iterate on all of node's children. */
        std::vector<State<S>> possibles = searchable.getAllPossibleStates(node);
        typename std::vector<State<S>>::iterator itor;

        for (itor = possibles.begin(); itor != possibles.end(); itor++) {

        }

    }
}

template <class P, class S>
S AStar<P,S>::search(ISearchable<P> searchable) {

}