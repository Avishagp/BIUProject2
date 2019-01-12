
#ifndef BIUPROJECT2_ASTAR_H
#define BIUPROJECT2_ASTAR_H

#include <vector>
#include <string>
#include <queue>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class AStar  : public PQSearcher<P,S>{
private:
    S searchInPossibleStates(ISearchable<P> searchable, State<S> *initial, State<S> *goal);
    int heuristic(ISearchable<P> searchable, State<S> a, State<S> b);
public:
    S search(ISearchable<P> searchable) override;
};


#endif //BIUPROJECT2_ASTAR_H
