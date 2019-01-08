
#include "SearchableMatrix.h"

SearchableMatrix::SearchableMatrix(int* mat, State<std::pair<int, int>> src, State<std::pair<int, int>> dst) {
    this->start = src;
    this->goal = dst;
    this->matrix = mat;
}

SearchableMatrix::SearchableMatrix(int* mat) {
    this->matrix = mat;
}


State<std::pair<int, int>> SearchableMatrix::getInitialState() {
    return this->start;
}

State<std::pair<int, int>> SearchableMatrix::getGoalState() {
    return this->goal;
}

std::vector<State<std::pair<int, int>>> SearchableMatrix::getAllPossibleStates(State<std::pair<int, int>> s) {
    return std::vector<State<std::pair<int, int>>>();
}
