
#ifndef BIUPROJECT2_BFS_H
#define BIUPROJECT2_BFS_H

#include <vector>
#include <queue>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class BreadthFirstSearch : public ISearcher<P,S> {
private:
    int numberOfNodesEvaluated;
public:
    BreadthFirstSearch() {
        numberOfNodesEvaluated = 0;
    }

    S search(ISearchable<P>* searchable) override {
        /* Get the initial state and the goal state from the searchable. */
        State<P> *initial = searchable->getInitialState();
        State<P> *goal = searchable->getGoalState();

        std::queue<State<P>*> qs;
        qs.push(initial);
        initial->setVisited(true);
        State<P>* node;

        /* Loop on every node. */
        while (!qs.empty()) {
            node = qs.front();
            qs.pop(); //delete the element we have just gotten.
            this->numberOfNodesEvaluated++;

            if (node->Equals(searchable->getGoalState())) {
                return goal;
            }

            /* Iterate on all of node's children. */
            std::vector<State<P>*> possibles = searchable->getAllPossibleStates(node);
            typename std::vector<State<P>*>::iterator itor;

            for (itor = possibles.begin(); itor != possibles.end(); itor++) {
                /* If a child node wasn't visited, add to queue. */
                if (!(*itor)->isVisited()) {
                    (*itor)->setVisited(true);
                    qs.push(*itor);
                    (*itor)->setCameFrom(node);
                }
            }
        }
        return node; //all sons weren't goal.
    }

    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }
};


#endif //BIUPROJECT2_BFS_H
