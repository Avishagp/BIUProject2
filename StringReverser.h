
#ifndef BIUPROJECT2_STRINGREVERSER_H
#define BIUPROJECT2_STRINGREVERSER_H

#include "Solver.h"
#include <algorithm>
#include <iterator>

//template <class T, class T2>
class StringReverser : public Solver<std::string,std::string> {

public:

    /**
     * Reverse a string.
     * @param problem The string to reverse.
     * @return the reversed string.
     */
    virtual std::string solveProblem(const std::string problem) {
        std::string solution = problem;
        std::reverse(solution.begin(),solution.end());
        return solution;
    }

};


#endif //BIUPROJECT2_STRINGREVERSER_H
