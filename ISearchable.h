
#ifndef BIUPROJECT2_ISEARCHANLE_H
#define BIUPROJECT2_ISEARCHANLE_H

#include <vector>
#include "State.h"

/**
 * Interface for a searchable object.
 * @tparam T - Depends on State implementation.
 */
template <class T>
class ISearchable {

public:

    //// GETTERS
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;

    /**
     * Return's a vector of all possible moves.
     * @param s The state we begin in.
     * @return a vector of all possible moves.
     */
    virtual std::vector<State<T>*> getAllPossibleStates(State<T>* s) = 0;

    /**
     * Destructor.
     */
    virtual ~ISearchable(){};
};


#endif //BIUPROJECT2_ISEARCHANLE_H
