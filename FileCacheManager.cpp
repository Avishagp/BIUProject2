
#include "FileCacheManager.h"

/**
 * Constructor.
 * @param path The path to the save file.
 */
FileCacheManager::FileCacheManager(std::string path) {
    filePath = path;
    loadAllSolutions();
}

/**
 * Check if a solution exist's.
 * @param solution - the solution to check.
 * @return Does the solution exist's in map;
 */
bool FileCacheManager::isSolutionExists(const std::string solution) {
    return (this->solutions.count(solution) > 0);
}

/**
 * If problem is solved return's it's solution, else an empty string.
 * @param problem A string representing the problem.
 * @return The solution.
 */
std::string FileCacheManager::getSolution(const std::string problem) {
    if (isSolutionExists(problem)) {
        return this->solutions.at(problem);
    } else {
        return "";
    }
}

/**
 * Saving the solution in a file.
 * @param problem save data.
 * @param solution save data.
 */
void FileCacheManager::saveSolution(const std::string problem, const std::string solution) {

    /* Create file object. */
    ofstream dataFile;
    dataFile.open(this->filePath, std::ios_base::app);

    /* Adding to map. */
    std::pair<std::string, std::string> pairToAdd;
    pairToAdd.first  = problem;
    pairToAdd.second = solution;
    this->solutions.insert(pairToAdd);

    /* Writing to file */
    dataFile << problem  << endl;
    dataFile << solution << endl;

    /* Closing file. */
    dataFile.close();
}

/**
 * Load's all the solutions from file to map.
 */
void FileCacheManager::loadAllSolutions() {

    /* The data holders. */
    std::string problem;
    std::string solution;
    ifstream data;
    data.open(this->filePath);

    if (!data.good()) {
        return;
    }

    /* Read a line from file. */
    while (std::getline(data, problem)) {

        std::getline(data, solution);
        std::pair<std::string, std::string> pairToAdd;
        pairToAdd.first  = problem;
        pairToAdd.second = solution;
        this->solutions.insert(pairToAdd);
    }

    data.close();
    return;
}
