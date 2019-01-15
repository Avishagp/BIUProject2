
#ifndef BIUPROJECT2_SEARCHABLEMATRIX_H
#define BIUPROJECT2_SEARCHABLEMATRIX_H

#include <string>
#include <sstream>
#include "State.h"
#include "ISearchable.h"

class SearchableMatrix : public ISearchable<std::pair<int,int>> {

private:

    //// MEMBERS

    std::vector<std::vector<State<std::pair<int,int>>*>> stateMatrix;
    std::vector<std::vector<int>> mazeMatrix;
    State<std::pair<int, int>>* goal;
    State<std::pair<int, int>>* start;

public:
    SearchableMatrix(std::string,std::string,std::string);
    void addRowToMaze(std::string);

public:
    State<std::pair<int, int>>* getInitialState() override;
    State<std::pair<int, int>>* getGoalState() override;
    std::vector<State<std::pair<int, int>>*> getAllPossibleStates(State<std::pair<int, int>>*) override;
    ~SearchableMatrix() override;
};


#endif //BIUPROJECT2_SEARCHABLEMATRIX_H
