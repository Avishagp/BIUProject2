
#include "MyClientHandler.h"

void MyClientHandler::handleClient(int socket_id) {

    bool isEndReached = true;
    std::string data_read;
    char buffer[1024];
    int number_of_bytes_read;

    /* Hold's the parameters we need for solver. */
    std::string maze;
    std::string start_pos = "";
    std::string goal_pos  = "";

    /* Hold's the parameters that we need to parse input. */
    int matrix_length= -1;
    int matrix_width = -1;
    int matrix_lines_read = 0;
    bool maze_read_finished = false;
    bool maze_positions_read = false;

    bool garbage = true;
    while (garbage) {
        /* Stop thread */
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    /* Read from server line by line until we receive "end". */
    while (isEndReached) {

        /* Clear buffer. */
        bzero(buffer, 1024);
        number_of_bytes_read = (int)read(socket_id, buffer, 1023);

        /* Check for reading failure. */
        if (number_of_bytes_read < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        data_read = buffer;

        /* Checking for end of message code. */
        if (data_read == "end" || data_read == "end\n" || data_read == "end\r\n") {

            /* Stopping the reading process. */
            isEndReached = false;
        } else {

            /* Check what are we reading currently */
            if (!maze_read_finished) {

                //// Reading the maze

                /* If we didn't already check size of matrix (Happens once). */
                if (matrix_length  < 0 || matrix_width < 0) {
                    int size = CountCharsInString(data_read, ',');
                    matrix_width  = size;
                    matrix_length = matrix_width;
                } else {

                    /* It is not the first line, make sure it has the same number of elements. */
                    int size = CountCharsInString(data_read, ',');
                    if (size != matrix_width) {
                        perror("Bad input");
                        return;
                    }

                }

                /* Checking if we finished reading the matrix. */
                matrix_lines_read++;
                if (matrix_lines_read == matrix_length) {
                    maze_read_finished = true;
                }

                /* Saving matrix line. */
                maze += data_read;

            } else if (!maze_positions_read) {

                //// Reading goal and start positions.

                /* Checking if are reading the start or goal position. */
                if (start_pos.empty()) {
                    /* Reading starting position. */
                    start_pos = data_read;
                } else if (goal_pos.empty()) {
                    /* Reading goal position. */
                    goal_pos = data_read;
                    maze_positions_read = true;
                }
            } else {

                //// We are done reading, this is incorrect input.
                perror("Bad input");
                return;
            }
        } // else
    } // while

    /* Checking we got all data we need in order to solve. */
    if (!maze_read_finished || !maze_positions_read || matrix_lines_read != matrix_length) {
        perror("Bad input");
        return;
    }

    /* Getting hash codes for values. */
    std::size_t  matrix_hash    = std::hash<std::string>{}(maze);
    std::size_t  start_pos_hash = std::hash<std::string>{}(start_pos);
    std::size_t  goal_pos_hash  = std::hash<std::string>{}(goal_pos);



    //todo call cacheManager and solver with searchable.
    close(socket_id);
}

int MyClientHandler::CountCharsInString(std::string str, char ch) {

    int number_of_commas = 0;

    for(char current_char : str) {
        if (current_char == ch) {
            number_of_commas++;
        }
    }

    return number_of_commas+1;
}
