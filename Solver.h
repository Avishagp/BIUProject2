
#ifndef BIUPROJECT2_SOLVER_H
#define BIUPROJECT2_SOLVER_H

#include "string"

template <class T, class T2>
class Solver {

private:

public:
    virtual T solveProblem(T2) = 0;
};


#endif //BIUPROJECT2_SOLVER_H
