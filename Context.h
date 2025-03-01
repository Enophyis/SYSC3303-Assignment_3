#ifndef CONTEXT_H
#define CONTEXT_H

#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#include <memory>
#include "State.h"

class Context {
private:
    std::unique_ptr<State> currentState;
    vehicleSignal_t vSignal = GREEN;
    pedestrianSignal_t pSignal = DONT_WALK;
    bool isPedestrianWaiting = false;

public:
    explicit Context(std::unique_ptr<State> initialState)
        : currentState(std::move(initialState)) {}  // Start with a given state

    void changeState(std::unique_ptr<State> state)
    {
        currentState = std::move(state);
    }

    void changePedestrianSignal(const pedestrianSignal_t newSignal)
    {
        pSignal = newSignal;
    }
    void changeVehicleSignal(const vehicleSignal_t newSignal)
    {
        vSignal = newSignal;
    }

    void changePedestrianWaiting(const bool newPedestrianWaiting)
    {
        isPedestrianWaiting = newPedestrianWaiting;
    }

    bool returnPedestrianWaiting() const
    {
        return isPedestrianWaiting;
    }

    void timeout() {
        currentState->timeout(*this);
    }

    void pedestrianWaiting() {
        currentState->pedestrianWaiting(*this);
    }

#ifdef DEBUG
    void printState()
    {
        currentState->printState();
    }
#endif

};

#endif // CONTEXT_H