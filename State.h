
#ifndef BIUPROJECT2_STATE_H
#define BIUPROJECT2_STATE_H

template <class T>
class State {

private:
    T state;
    double cost;
    State<T> cameFrom;

public:

    //// CONSTRUCTORS

    State(){}

    State(T status) {
        this->state = status;
    }

    State (T status, int costTo, State<T> &prev) {
        this->state    = status;
        this->cost     = costTo;
        this->cameFrom = prev;
    }

    //// CHECKERS

    bool Equals(State<T> s) {
        return this->state == (s.state);
    }

    //// SETTERS

    void setState(T status) {
        this->state = status;
    }

    void setCost(int costTo) {
        this->cost = costTo;
    }

    void setCameFrom(const State<T> &prev) {
        this->cameFrom = prev;
    }

    //// GETTERS

    T getState() const {
        return this->state;
    }

    int getCost() const {
        return this->cost;
    }

    const State<T> &getCameFrom() const {
        return this->cameFrom;
    }
};


#endif //BIUPROJECT2_STATE_H
