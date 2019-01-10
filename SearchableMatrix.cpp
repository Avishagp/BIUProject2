

#include "SearchableMatrix.h"




State<std::pair<int, int>> SearchableMatrix::getInitialState() {
    return this->start;
}

State<std::pair<int, int>> SearchableMatrix::getGoalState() {
    return this->goal;
}

std::vector<State<std::pair<int, int>>> SearchableMatrix::getAllPossibleStates(State<std::pair<int, int>> s) {
    return std::vector<State<std::pair<int, int>>>();
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
