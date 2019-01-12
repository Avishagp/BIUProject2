

#include "SearchableMatrix.h"


SearchableMatrix::SearchableMatrix(std::string maze) {

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

std::vector<State<std::pair<int, int>>*> SearchableMatrix::getAllPossibleStates(State<std::pair<int, int>>* s) {

    std::vector<State<std::pair<int, int>>*> result;

    /* Get matrix bounds. */
    int number_of_rows = this->mazeMatrix.at(0).size();
    int number_of_cols = this->mazeMatrix.size();

    /* Get current position. */
    unsigned int current_i = (unsigned int)s->getState().first;
    unsigned int current_j = (unsigned int)s->getState().second;

    //todo check we dont go to prev.
//    State<std::pair<int, int>> prev = s.getCameFrom();


    /* Add Down. */
    if (current_i != 0 ) {
        if (this->mazeMatrix.at(current_i - 1).at(current_j) != -1 ) {
            result.push_back(this->stateMatrix.at(current_i-1).at(current_j));
        }
    }

    /* Add Up. */
    if (current_i != (number_of_cols - 1)) {
        if (this->mazeMatrix.at(current_i + 1).at(current_j) != -1 ) {
            result.push_back(this->stateMatrix.at(current_i+1).at(current_j));
        }
    }

    /* Add Left. */
    if (current_j != 0) {
        if (this->mazeMatrix.at(current_i).at(current_j - 1) != -1 ) {
            result.push_back(this->stateMatrix.at(current_i).at(current_j-1));
        }
    }

    /* Add Right. */
    if (current_j != (number_of_rows - 1)) {
        if (this->mazeMatrix.at(current_i).at(current_j + 1) != -1 ) {
            result.push_back(this->stateMatrix.at(current_i).at(current_j+1));
        }
    }

    return result;
}

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
