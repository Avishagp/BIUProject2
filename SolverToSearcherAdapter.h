
#ifndef BIUPROJECT2_SOLVERTOSEARCHERADAPTER_H
#define BIUPROJECT2_SOLVERTOSEARCHERADAPTER_H

#include "Solver.h"
#include "ISearcher.h"
#include "ISearcher.h"

/**
 * This class is an adapter between a Solver and a ISearcher objects.
 */
class SolverToSearcherAdapter : public Solver<ISearchable<std::pair<int,int>>*,State<std::pair<int,int>>*> {

private:
    ISearcher< std::pair<int, int> , State<std::pair<int,int>>*>* searcher;

public:

    /**
     * Constructor
     * @param searcher The search method.
     */
    SolverToSearcherAdapter(ISearcher<std::pair<int,int>, State<std::pair<int,int>>*> *searcher) : searcher(searcher) {}

    /**
     * Solve's the problem - Search using provided method.
     * @param searchable - The structure to search in.
     * @return A string of directions to solution.
     */
    State<std::pair<int,int>>* solveProblem(ISearchable< std::pair<int, int> >* searchable) override {
        return searcher->search(searchable);
    }

};


#endif //BIUPROJECT2_SOLVERTOSEARCHERADAPTER_H
