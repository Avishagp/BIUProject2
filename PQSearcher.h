
#ifndef BIUPROJECT2_PQSEARCHER_H
#define BIUPROJECT2_PQSEARCHER_H

#include <set>
#include <queue>
#include "StateComparatorLesser.h"
#include "State.h"
#include "ISearcher.h"

/**
 * Define's a searcher that uses a priority queue.
 * @tparam P The State generic parameter.
 * @tparam S The object we want to get from search.
 */
template <class P, class S>
class PQSearcher : public ISearcher<P,S> {
public:

    /* A priority queue as a multiset, gets compare method from constructor. */
    std::multiset<State<P>*,bool (*)(State<P>* a, State<P>* b)> stateSet;

    /* Hold's the number of evaluated nodes. */
    int numberOfNodesEvaluated;

    /**
     * Constructor.
     * @param cmp_func the compare function for multiset.
     */
    PQSearcher(bool (*cmp_func)(State<P>* a, State<P>* b)) : numberOfNodesEvaluated(0), stateSet(cmp_func){}

    /**
     * Find a specific State in multiset.
     * @param to_find The State to find.
     * @return iterator to the State.
     */
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

    /**
     * Delete a specific State from multiset.
     * @param to_delete The State to delete.
     */
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

    /**
     * The search method, pure virtual.
     * @param searchable VIRTUAL
     * @return VIRTUAL
     */
    virtual S search(ISearchable<P>* searchable) = 0;

    /**
     * Returns the number of nodes the search evaluated.
     * @return the number of nodes the search evaluated.
     */
    int getNumberOfNodesEvaluated() override {
        return this->numberOfNodesEvaluated;
    }

    ~PQSearcher() override {};

};

#endif //BIUPROJECT2_PQSEARCHER_H
