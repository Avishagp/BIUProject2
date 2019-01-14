
#ifndef BIUPROJECT2_SEARCHER_H
#define BIUPROJECT2_SEARCHER_H

#include "ISearchable.h"

/**
 * Define's a searcher.
 * @tparam P The State generic parameter.
 * @tparam S The object we want to get from search.
 */
template <class P, class S>
class ISearcher {
public:

    /**
     * The search method.
     * @param searchable The searchable object.
     * @return The search result
     */
    virtual S search(ISearchable<P>* searchable) = 0;

    /**
     * Returns the number of nodes the search evaluated.
     * @return the number of nodes the search evaluated.
     */
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //BIUPROJECT2_SEARCHER_H
