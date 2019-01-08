
#ifndef BIUPROJECT2_SEARCHABLEMATRIX_H
#define BIUPROJECT2_SEARCHABLEMATRIX_H

#include "State.h"
#include "ISearchable.h"

class SearchableMatrix : public ISearchable<std::pair<int,int>> {

private:
    int* matrix;
    //todo get rid of matrix? get size?
    State<std::pair<int, int>> goal;
    State<std::pair<int, int>> start;
public:

    SearchableMatrix(int*,State<std::pair<int, int>>,State<std::pair<int, int>>);
    SearchableMatrix(int*);

    virtual State<std::pair<int, int>> getInitialState();
    virtual State<std::pair<int, int>> getGoalState();
    virtual std::vector<State<std::pair<int, int>>> getAllPossibleStates(State<std::pair<int, int>> s);
};


#endif //BIUPROJECT2_SEARCHABLEMATRIX_H
