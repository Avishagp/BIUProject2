
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socketfd) {
    /* Read from server line by line until isEndReached is false ("end" line reached). */
    bool isEndReached = true;
    string current;
    char buffer[1024];
    int n;

    while (isEndReached) {

        /* Read current line. */
        bzero(buffer, 1024);

        n = (int)read(socketfd, buffer, 1023);

        current = buffer;

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (current == "end" || current == "end\n" || current == "end\r\n") {
            /* Reading should end. */
            isEndReached = false;
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

            /* Write solution to the client.
             * Flush is used so that the output will be flushed instantly - changes will be written to
             * memory. */
            n = write(socketfd, solution.c_str(), (int)(solution.length()));

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    }

    //close(socketfd);
}