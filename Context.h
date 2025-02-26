#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"
#include <memory>

class Context {
private:
    std::unique_ptr<State> currentState;

public:
    explicit Context(std::unique_ptr<State> initialState) : currentState(std::move(initialState)) {}

    void setState(std::unique_ptr<State> newState) {
        currentState = std::move(newState);
    }

    void timeout() {
        currentState->timeout(*this);
    }

    void pedestrianWaiting() {
        currentState->pedestrianWaiting(*this);
    }
};

#endif // CONTEXT_H
