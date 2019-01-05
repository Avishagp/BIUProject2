
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(stringstream input, stringstream output) {
    /* Read from input stream line by line until isEndReached is false ("end" line reached). */
    bool isEndReached = true;
    string current;

    while (isEndReached) {
        /* Read current line. */
        getline(input, current);

        if (current == "end") {
            /* Reading should end. */
            isEndReached = true;
        } else {
            bool isSolution = cacheManager->isSolutionExists(current);
            string solution;

            /* If there's a solution for the current string, get it and write it to the client.
             * Else, use solver, save the solution at cacheManager and write it to the client. */
            if (isSolution) {
                solution = cacheManager->getSolution(current);
            } else {
                solution = solver->solveProblem(current);
                cacheManager->saveSolution(current, solution);
            }

            /* Write solution to the output stream (client).
             * Flush is used so that the output will be flushed instantly - changes will be written to
             * memory. */
            output << solution << flush;
        }
    }
}