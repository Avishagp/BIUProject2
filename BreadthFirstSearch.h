
#ifndef BIUPROJECT2_BFS_H
#define BIUPROJECT2_BFS_H

#include <vector>
#include <queue>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class BreadthFirstSearch : public ISearcher<P,S> {
private:
    S searchInAllPossibleStates(ISearchable<P> searchable, State<S> *initial, State<S> *goal);
public:
    S search(ISearchable<P> searchable) override;
};


#endif //BIUPROJECT2_BFS_H
