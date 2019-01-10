
#ifndef BIUPROJECT2_STATECOMPARATORLESSER_H
#define BIUPROJECT2_STATECOMPARATORLESSER_H

#include "State.h"

template <class T>
class StateComparatorLesser {
    bool operator() (const State<T>& a, const State<T>& b) const {
        return (a.getCost() < b.getCost());
    }
};


#endif //BIUPROJECT2_STATECOMPARATORLESSER_H
