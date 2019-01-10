
#ifndef BIUPROJECT2_SOLVER_H
#define BIUPROJECT2_SOLVER_H

#include "string"

template <class P, class S>
class Solver {

private:

public:
    virtual S solveProblem(P) = 0;
    virtual ~Solver(){};
};


#endif //BIUPROJECT2_SOLVER_H
