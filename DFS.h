
#ifndef BIUPROJECT2_DFS_H
#define BIUPROJECT2_DFS_H

#include <vector>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class DFS : public PQSearcher<P,S> {
private:
    S searchInPossibleStates(ISearchable<P> searchable, std::vector<State<S>> possible, State<S> goal);
public:
    S search(ISearchable<P> searchable) override;
};


#endif //BIUPROJECT2_DFS_H
