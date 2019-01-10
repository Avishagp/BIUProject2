
#ifndef BIUPROJECT2_SEARCHER_H
#define BIUPROJECT2_SEARCHER_H

#include "ISearchable.h"

template <class P, class S>
class ISearcher {
    virtual S search(ISearchable<P> searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //BIUPROJECT2_SEARCHER_H
