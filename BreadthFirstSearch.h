
#ifndef BIUPROJECT2_BFS_H
#define BIUPROJECT2_BFS_H

#include <vector>
#include <queue>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class BreadthFirstSearch : public ISearcher<P,S> {
public:
    S search(ISearchable<P>* searchable) override {
        /* Get the initial state and the goal state from the searchable. */
        State<S> *initial = searchable->getInitialState();
        State<S> *goal = searchable->getGoalState();

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
            std::vector<State<S>> possibles = searchable->getAllPossibleStates(node);
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
};


#endif //BIUPROJECT2_BFS_H
