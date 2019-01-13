
#ifndef BIUPROJECT2_DFS_H
#define BIUPROJECT2_DFS_H

#include <vector>
#include <string>
#include <stack>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class DepthFirstSearch : public ISearcher<P,S> {
private:
    int numberOfNodesEvaluated;
public:
    DepthFirstSearch() {
        numberOfNodesEvaluated = 0;
    }

    S search(ISearchable<P>* searchable) override {
        /* Get the initial state and the goal state from the searchable. */
        State<P>* current = searchable->getInitialState();
        State<P>* goal = searchable->getGoalState();

        /* Create a stack */
        std::stack<State<P>*> stack;

        /* Push the initial node. */
        stack.push(current);
        current->setVisited(true);
        State<P>* top;

        while (!stack.empty()) {
            this->numberOfNodesEvaluated++;
            top = stack.top();
            stack.pop();

            if (top->Equals(searchable->getGoalState())) {
                return goal;
            }

            std::vector<State<P>*> possibilities = searchable->getAllPossibleStates(top);
            typename std::vector<State<P>*>::iterator itor;

            for (itor = possibilities.begin(); itor != possibilities.end(); itor++) {
                if ((!(*itor)->isVisited()) && ((*itor)->getCost() != -1)) { //add every adjacent that's not visited to the stack.
                    stack.push(*itor);
                }
            }
        }

        return top;
    }

    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }
};


#endif //BIUPROJECT2_DFS_H
