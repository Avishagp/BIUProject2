
#ifndef BIUPROJECT2_BFS_H
#define BIUPROJECT2_BFS_H

#include <vector>
#include "PQSearcher.h"
#include "State.h"

template <class P, class S>

class BFS : public PQSearcher<P,S> {
public:
    S search(ISearchable<P> searchable) override;
};


#endif //BIUPROJECT2_BFS_H
