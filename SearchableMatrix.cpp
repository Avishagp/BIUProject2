

#include "SearchableMatrix.h"

SearchableMatrix::SearchableMatrix(std::string maze, std::string start, std::string goal) {

    std::string tempVal;
    std::stringstream lineParser;

    lineParser.str(start);
    std::getline(lineParser, tempVal, ',');
    int start_i = std::stoi(tempVal);
    std::getline(lineParser, tempVal, ',');
    int start_j = std::stoi(tempVal);

    lineParser.clear();
    lineParser.str(goal);
    std::getline(lineParser, tempVal, ',');
    int goal_i = std::stoi(tempVal);
    std::getline(lineParser, tempVal, ',');
    int goal_j = std::stoi(tempVal);
    lineParser.clear();

    //// Build mazeMatrix

    /* A stream to parse with. */
    std::stringstream linesParser;
    //std::stringstream lineParser;
    linesParser.str(maze);

    /* Splitting the date to elements. */
    while (linesParser.good()) {
        std::vector<int> rowToAdd;
        std::string tempLine;
        std::getline(linesParser, tempLine, '\n');

        /* If the line is not empty parse it. */
        if (!tempLine.empty()) {
            lineParser.str(tempLine);

            /* Splitting the date to elements. */
            while (lineParser.good()) {
                std::string tempVal;
                std::getline(lineParser, tempVal, ',');
                rowToAdd.push_back(std::stoi(tempVal));
            }
            lineParser.clear();
            this->mazeMatrix.push_back(rowToAdd);
        }
    }

    //// Build stateMatrix
    unsigned int i = 0, j = 0;
    auto it1 = this->mazeMatrix.begin();
    for (; it1 != this->mazeMatrix.end(); ++it1) {
        std::vector<State<std::pair<int,int>>*> stateRow;
        auto it2 = it1->begin();
        for (; it2 != it1->end(); ++it2) {
            std::pair<int,int> insertPair(i,j);
            double insertCost = this->mazeMatrix.at(i).at(j);
            stateRow.push_back(new State<std::pair<int,int>>(insertPair, insertCost, nullptr));
            ++j;
        }
        ++i;
        j = 0;
        this->stateMatrix.push_back(stateRow);
    }

    this->start = this->stateMatrix.at(start_i).at(start_j);
    this->goal  = this->stateMatrix.at(goal_i).at(goal_j);
}

/**
 * Returns all the possible moves from a State.
 * @param s The state to move from.
 * @return A vector of States.
 */
std::vector<State<std::pair<int, int>>*> SearchableMatrix::getAllPossibleStates(State<std::pair<int, int>>* s) {

    std::vector<State<std::pair<int, int>>*> result;

    /* Get matrix bounds. */
    int number_of_rows = this->mazeMatrix.at(0).size();
    int number_of_cols = this->mazeMatrix.size();

    /* Get current position. */
    unsigned int current_i = (unsigned int)s->getState().first;
    unsigned int current_j = (unsigned int)s->getState().second;

    /* Get previous State state if exist's. */
    std::pair<int, int> prevStatePos;
    bool isPrev = false;
    if (s->getCameFrom() != nullptr) {
        prevStatePos = s->getCameFrom()->getState();
    } else {
        isPrev = true;
    }

    /*
     * Adding to vector if:
     * 1- There is a State in this direction (Not out of bounds)
     * 2- The State we go to is not -1 (inf.)
     * 3- The State we go to is not the previous one.
    */

    /* Add Up. */
    if (current_i != 0) {
        if (this->mazeMatrix.at(current_i - 1).at(current_j) != -1) {
            if (isPrev || (this->stateMatrix.at(current_i-1).at(current_j)->getState() != prevStatePos)) {
                result.push_back(this->stateMatrix.at(current_i-1).at(current_j));
            }
        }
    }

    /* Add Down. */
    if (current_i != (number_of_cols - 1)) {
        if (this->mazeMatrix.at(current_i + 1).at(current_j) != -1 ) {
            if (isPrev || (this->stateMatrix.at(current_i+1).at(current_j)->getState() != prevStatePos)) {
                result.push_back(this->stateMatrix.at(current_i+1).at(current_j));
            }
        }
    }

    /* Add Left. */
    if (current_j != 0 && ((current_i != prevStatePos.first) || (current_j-1 != prevStatePos.second))) {
        if (this->mazeMatrix.at(current_i).at(current_j - 1) != -1 ) {
            if (isPrev ||  (this->stateMatrix.at(current_i).at(current_j-1)->getState() != prevStatePos)) {
                result.push_back(this->stateMatrix.at(current_i).at(current_j-1));
            }
        }
    }

    /* Add Right. */
    if (current_j != (number_of_rows - 1)) {
        if (this->mazeMatrix.at(current_i).at(current_j + 1) != -1 ) {
            if (isPrev || (this->stateMatrix.at(current_i).at(current_j+1)->getState() != prevStatePos)) {
                result.push_back(this->stateMatrix.at(current_i).at(current_j+1));
            }
        }
    }

    return result;
}

State<std::pair<int, int>> *SearchableMatrix::getInitialState() {
    return this->start;
}

State<std::pair<int, int>> *SearchableMatrix::getGoalState() {
    return this->goal;
}

SearchableMatrix::~SearchableMatrix() {

    auto it1 = this->stateMatrix.begin();
    for (; it1 != this->stateMatrix.end(); ++it1) {

        auto it2 = it1->begin();
        for (; it2 != it1->end(); ++it2) {
            delete(*it2);
        }
    }

}
