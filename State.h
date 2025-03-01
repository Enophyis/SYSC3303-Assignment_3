//
// Created by atcjw on 2/25/2025.
//

#ifndef STATE_H
#define STATE_H

#include <chrono>
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>

class Context;

enum vehicleSignal_t
{
    GREEN = 0,
    YELLOW = 1,
    RED = 2
};

enum pedestrianSignal_t
{
    BLANK = 0,
    WALK = 1,
    DONT_WALK = 2
};

class State{
private:
    bool isAlive = true;
    std::thread timerThread;
    std::mutex timerMutex;
    std::condition_variable timerCV;
    std::string stateName;
public:

    virtual ~State() {isAlive = false;}

    virtual void timeout(Context& context) = 0;

    void pedestrianWaiting(Context& context);
    void signalVehicles(vehicleSignal_t signal, Context& context);
    void signalPedestrians(pedestrianSignal_t signal, Context& context);
    void setTimer(int timer, Context& context);
    void killTimer();
    //debug functions
    void printState();
};
//============== Declarations for Vehicles and subclasses==================
class VehiclesEnabled : public State {

public:
    explicit VehiclesEnabled(std::string stateName, Context& context);
    void timeout(Context& context) override;

};

class VehiclesGreen : public VehiclesEnabled {
private:
    bool isPedestrianWaiting = false;
public:
    explicit VehiclesGreen(std::string stateName, Context& context);
    void timeout(Context &context) override;
};

class VehiclesGreenInt : public VehiclesEnabled
{
public:
    explicit VehiclesGreenInt(std::string stateName, Context& context);
    void timeout(Context &context) override;


};

class VehiclesYellow : public VehiclesEnabled
{
public:
    explicit VehiclesYellow(std::string stateName, Context& context);
    void timeout(Context& context) override;


};

//============== Declarations for Pedestrians and subclasses==================

class PedestriansEnabled : public State
{
public:
    explicit PedestriansEnabled(std::string stateName, Context& context);
    void timeout(Context& context) override;

};

class PedestriansWalk : public PedestriansEnabled {
public:
    explicit PedestriansWalk(std::string stateName, Context& context);
    void timeout(Context &context) override;
};

class PedestriansFlash : public PedestriansEnabled {
private:
    int flashCounter = 7;

public:
    explicit PedestriansFlash(std::string stateName, Context& context);
    void timeout(Context &context) override;
    void entryAction(Context& context);

};

#endif //STATE_H
