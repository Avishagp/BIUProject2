
#ifndef BIUPROJECT2_SOLVER_H
#define BIUPROJECT2_SOLVER_H

#include "string"

/**
 * Define's a Solver.
 * @tparam P The problem.
 * @tparam S The solution.
 */
template <class P, class S>
class Solver {

public:

    /**
     * The solver method.
     * @return Solution.
     */
    virtual S solveProblem(P) = 0;

    /**
     * Destructor.
     */
    virtual ~Solver(){};
};


#endif //BIUPROJECT2_SOLVER_H
