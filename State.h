
#ifndef BIUPROJECT2_STATE_H
#define BIUPROJECT2_STATE_H

template <class T>
class State {

private:
    T state;
    double cost;
    State<T>* cameFrom;
    bool visited;

public:

    //// CONSTRUCTORS

    State (T status, double costTo, State<T>* prev) {
        this->state    = status;
        this->cost     = costTo;
        this->cameFrom = prev;
        this->visited  = false;
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

    void setVisited(bool val) {
        this->visited = val;
    }

    //// GETTERS

    T getState() const {
        return this->state;
    }

    double getCost() const {
        return this->cost;
    }

    bool getVisited() {
        return this->visited;
    }

    State<T>* getCameFrom() const {
        return cameFrom;
    }

    bool isVisited() const {
        return visited;
    }

    //// DESTRUCTOR

    ~State(){};
};


#endif //BIUPROJECT2_STATE_H
