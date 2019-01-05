
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

int main() {



    Solver<std::string,std::string>* solver = new StringReverser();
    CacheManager* fileCacheManager = new FileCacheManager("reverse.txt");
    std::string problem = "Bla";
    std::string solution;
    if (fileCacheManager->isSolutionExists(problem)) {
        solution = fileCacheManager->getSolution(problem);
    } else {
        solution = solver->solveProblem(problem);
        fileCacheManager->saveSolution(problem, solution);
    }
    cout << "problem : "<< "\"" << problem << "\"" << endl << "solution: " <<  "\"" <<solution << "\"" << endl;
    delete(solver);
}
