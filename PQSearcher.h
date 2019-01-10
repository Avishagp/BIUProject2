
#ifndef BIUPROJECT2_PQSEARCHER_H
#define BIUPROJECT2_PQSEARCHER_H

#include <set>
#include <queue>
#include "State.h"
#include "ISearcher.h"

template <class P, class S>
class PQSearcher : public ISearcher<P,S> {
private:
    std::priority_queue<State<P>> priorityQueue;
    int numberOfNodesEvaluated;
public:
    PQSearcher() { this->numberOfNodesEvaluated = 0; }
    int PriorityQueueSize() {
        return this->priorityQueue.size();
    }
private:
   virtual S search(ISearchable<P> searchable) = 0;
    int getNumberOfNodesEvaluated() override {
        return this->numberOfNodesEvaluated;
    }
};


#endif //BIUPROJECT2_PQSEARCHER_H