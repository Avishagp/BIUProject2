
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

    typename std::multiset<State<P>*,StateComparatorLesser<P>>::iterator findInSet (State<P>* find) {

        typename std::multiset<State<P>*,StateComparatorLesser<P>>::iterator is_in_open;
        auto eqr = this->stateSet.equal_range(find);
        auto it = eqr.first;

        for (; it != eqr.second; ++it) {

            if ((*it)->getState() == find->getState()) {
                return it;
            }
        }

        return this->stateSet.end();
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
