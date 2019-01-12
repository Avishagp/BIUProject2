
#ifndef BIUPROJECT2_PQSEARCHER_H
#define BIUPROJECT2_PQSEARCHER_H

#include <set>
#include <queue>
#include "StateComparatorLesser.h"
#include "State.h"
#include "ISearcher.h"

template <class P, class S>
class PQSearcher : public ISearcher<P,S> {
public:
    //std::set<State<P>*,StateComparatorLesser<P>> openList;
    std::multiset<State<P>*,bool (*)(State<P>* a, State<P>* b)> stateSet;
    int numberOfNodesEvaluated;

    PQSearcher(bool (*cmp_func)(State<P>* a, State<P>* b)) : numberOfNodesEvaluated(0), stateSet(cmp_func){}

    typename std::multiset<State<P>*,StateComparatorLesser<P>>::iterator findInSet (State<P>* to_find) {

        auto equal_range = this->stateSet.equal_range(to_find);
        auto iterator = equal_range.first;

        for (; iterator != equal_range.second; ++iterator) {

            if ((*iterator)->getState() == to_find->getState()) {
                return iterator;
            }
        }

        return this->stateSet.end();
    }

    void deleteInSet (State<P>* to_delete) {

        auto eqr = this->stateSet.equal_range(to_delete);
        auto iterator = eqr.first;

        for (; iterator != eqr.second; ++iterator) {

            if ((*iterator)->getState() == to_delete->getState()) {
                this->stateSet.erase(iterator);
                return;
            }
        }
    }

    int PriorityQueueSize() {
        return this->priorityQueue.size();
    }

    virtual S search(ISearchable<P>* searchable) = 0;

    int getNumberOfNodesEvaluated() override {
        return this->numberOfNodesEvaluated;
    }

};

#endif //BIUPROJECT2_PQSEARCHER_H
