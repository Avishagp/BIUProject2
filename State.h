
#ifndef BIUPROJECT2_STATE_H
#define BIUPROJECT2_STATE_H

/**
 * Define's a State.
 * @tparam T The state of the State.
 */
template <class T>
class State {

private:

    //// Data Members.
    T state;
    int distance_from_start;
    double total_cost_to;
    double cost;
    double original_cost;
    State<T>* cameFrom;
    bool visited;

public:

    //// CONSTRUCTORS

    State (T status, double costTo, State<T>* prev) {
        this->state    = status;
        this->cost     = costTo;
        this->cameFrom = prev;
        this->visited  = false;
        this->original_cost       = costTo;
        this->distance_from_start = 0;
        this->total_cost_to       = costTo;
    }

    //// CHECKERS

    bool Equals(const State<T>* s) {
        return this->state == (s->state);
    }

    //// SETTERS

    void setDistance_from_start(int distance_from_start) {
        this->distance_from_start = distance_from_start;
    }

    void setCost(double costTo) {
        this->cost = costTo;
    }

    void setCameFrom(State<T>* prev) {
        this->cameFrom = prev;
    }

    void setVisited(bool val) {
        this->visited = val;
    }

    void setTotal_cost_to(double total_cost_to) {
        State::total_cost_to = total_cost_to;
    }

    //// GETTERS

    T getState() const {
        return this->state;
    }

    double getCost() const {
        return this->cost;
    }

    State<T>* getCameFrom() const {
        return cameFrom;
    }

    bool getVisited() const {
        return this->visited;
    }

    bool isVisited() const {
        return visited;
    }

    double getOriginal_cost() const {
        return original_cost;
    }

    int getDistance_from_start() const {
        return distance_from_start;
    }

    double getTotal_cost_to() const {
        return total_cost_to;
    }

    //// DESTRUCTOR

    ~State(){};
};


#endif //BIUPROJECT2_STATE_H
