

#include "SearchableMatrix.h"

/**
 * Constructor, gets a string and builds the StateMatrix.
 * @param maze The maze as a string.
 */
SearchableMatrix::SearchableMatrix(std::string maze) {

    //todo skip the building of the mazeMatrix!
    //// Build mazeMatrix

    /* A stream to parse with. */
    std::stringstream linesParser;
    std::stringstream lineParser;
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

    this->start = this->stateMatrix.at(0).at(0);
    this->goal  = this->stateMatrix.at(i-1).at(i-1);

}

/**
 * Return's a vector of all possible moves.
 * @param s The state we begin in.
 * @return a vector of all possible moves.
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

/**
 * Adding a row to the maze, in case we want to build step by step.
 * @param newRow The new row.
 */
void SearchableMatrix::addRowToMaze(std::string newRow) {

    std::vector<int> rowToAdd;

    /* A stream to parse with. */
    std::stringstream lineParser;
    lineParser.str(newRow);

    /* Splitting the date to elements. */
    while (lineParser.good()) {
        std::string temp;
        std::getline(lineParser, temp, ',');
        rowToAdd.push_back(std::stoi(temp));
    }

    lineParser.clear();
    this->mazeMatrix.push_back(rowToAdd);
}

//// GETTERS
State<std::pair<int, int>> *SearchableMatrix::getInitialState() {
    return this->start;
}

State<std::pair<int, int>> *SearchableMatrix::getGoalState() {
    return this->goal;
}

/**
 * Calculate the linear distance between two States.
 * @param slot1 First State.
 * @param slot2 Second State.
 * @return The linear distance between two States.
 */
int SearchableMatrix::getDistance(State<std::pair<int, int>>* slot1, State<std::pair<int, int>>* slot2) {
    int x1 = slot1->getState().first;
    int y1 = slot1->getState().second;
    int x2 = slot2->getState().first;
    int y2 = slot2->getState().second;

    return abs(x1 - x2) + abs(y1 - y2);
}

/**
 * Destructor, Free all the States we created.
 */
SearchableMatrix::~SearchableMatrix() {
    auto it1 = this->stateMatrix.begin();
    for (; it1 != this->stateMatrix.end(); ++it1) {
        auto it2 = it1->begin();
        for (; it2 != it1->end(); ++it2) {
            delete(*it2);
        }
    }

}

