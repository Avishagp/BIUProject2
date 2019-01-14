
#ifndef BIUPROJECT2_CACHEMANAGER_H
#define BIUPROJECT2_CACHEMANAGER_H

#include <string>

/*
 * Define's a  Cache Manager object.
 */
class CacheManager {
public:

    /**
     * Check if solution exist's.
     * @param problem The problem.
     * @return if solution exist's.
     */
    virtual bool isSolutionExists(std::string problem) = 0;

    /**
     * Get's solution from memory.
     * @param problem The problem to solve.
     * @return The solution as a string.
     */
    virtual std::string getSolution(std::string problem) = 0;

    /**
     * Save a problem solution pair.
     * @param problem The problem.
     * @param solution The solution.
     */
    virtual void saveSolution(std::string problem, std::string solution) = 0;
};


#endif //BIUPROJECT2_CACHEMANAGER_H
