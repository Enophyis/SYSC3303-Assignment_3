//
// Created by atcjw on 3/1/2025.
//

// State.cpp
#include "State.h"
#include "Context.h"
#include <iostream>


void State::signalVehicles(vehicleSignal_t signal, Context& context)
{
    std::cout << "Vehicle Signals Now ";
    switch (signal)
    {
    case GREEN:
        std::cout << "Green";
        break;
    case YELLOW:
        std::cout << "Yellow";
        break;
    case RED:
        std::cout << "Red";
        break;
    default:
        std::cout << "Unknown";
    }
    std::cout << std::endl;
    context.changeVehicleSignal(signal);
}

void State::signalPedestrians(pedestrianSignal_t signal, Context& context)
{
    std::cout << "Pedestrian Signal Now ";
    switch (signal)
    {
    case BLANK:
        std::cout << "Blank";
        break;
    case WALK:
        std::cout << "Walk";
        break;
    case DONT_WALK:
        std::cout << "Don't Walk";
        break;
    default:
        std::cout << "Unknown";
    }
    std::cout << std::endl;
    context.changePedestrianSignal(signal);
}

void State::pedestrianWaiting(Context& context)
{
    context.changePedestrianWaiting(true);
}

void State::setTimer(int duration, Context& context) {
    std::thread([this, duration, &context]() {
        std::this_thread::sleep_for(std::chrono::seconds(duration));

        std::lock_guard<std::mutex> lock(timerMutex);
        if (this->isAlive) {  // ✅ Only call timeout() if the state is still valid
            timeout(context);
        }
    }).detach();
}

void State::killTimer() {
        std::lock_guard<std::mutex> lock(timerMutex);
        timerCV.notify_all();
}

void State::printState()
{
    std::cout << stateName << std::endl;
}

//===========================methods for VehiclesEnabled==================================
void VehiclesEnabled::timeout(Context& context) {
    context.changeState(std::make_unique<VehiclesGreen>("VehiclesGreen",context));
}
VehiclesEnabled::VehiclesEnabled(std::string stateName, Context& context){
    signalPedestrians(DONT_WALK, context);
    setTimer(1, context);
}




//===========================methods for VehiclesGreen==================================
void VehiclesGreen::timeout(Context& context)
{
    if(context.returnPedestrianWaiting())
    {
        context.changeState(std::make_unique<VehiclesYellow>("VehiclesYellow", context));
    }
    else
    {
        context.changeState(std::make_unique<VehiclesGreenInt>("VehiclesGreenInt", context));
    }
}

VehiclesGreen::VehiclesGreen(std::string stateName, Context& context) : VehiclesEnabled::VehiclesEnabled(stateName,context) {
    // Entry Action: Signal pedestrians to stop walking
    signalVehicles(GREEN, context);
    setTimer(10, context);
}



// =======================================VehiclesGreenInt=================================================
void VehiclesGreenInt::timeout(Context& context)
{
    context.changeState(std::make_unique<VehiclesYellow>("VehiclesYellow",context));
}
 VehiclesGreenInt::VehiclesGreenInt(std::string stateName, Context& context) : VehiclesEnabled(stateName,context)
{
    context.pedestrianWaiting();
    setTimer(1, context);
}


// VehiclesYellow.cpp
void VehiclesYellow::timeout(Context& context)
{
    context.changeState(std::make_unique<PedestriansEnabled>("PedestriansEnabled",context));
}
VehiclesYellow::VehiclesYellow(std::string stateName, Context& context) : VehiclesEnabled(stateName, context)
{
    signalVehicles(YELLOW,context);
    setTimer(3, context);
}


// PedestriansEnabled.cpp

void PedestriansEnabled::timeout(Context& context)
{
    context.changeState(std::make_unique<PedestriansWalk>("PedestriansWalk", context));
}
PedestriansEnabled::PedestriansEnabled(std::string stateName, Context& context)
{
    signalVehicles(RED, context);
    setTimer(1, context);
}



// PedestriansWalk.cpp
void PedestriansWalk::timeout(Context& context)
{
    context.changeState(std::make_unique<PedestriansFlash>("PedestriansFlash", context));
}
PedestriansWalk::PedestriansWalk(std::string stateName, Context& context) : PedestriansEnabled(stateName,context)
{
    signalPedestrians(WALK, context);
    setTimer(15, context);
}


// PedestriansFlash.cpp

void PedestriansFlash::entryAction(Context& context) {
    for (int i = flashCounter; i > 0; i--) {
        if (i & 1 == 0) {
            signalPedestrians(DONT_WALK, context);
            std::cout << "DONTWALK" << std::endl;
        } else {
            signalPedestrians(BLANK, context);
            std::cout << "BLANK" << std::endl;
        }
        std::cout << "flash" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Delay flashing
    }
}


PedestriansFlash::PedestriansFlash(std::string stateName, Context& context) : PedestriansEnabled(stateName,context)
{
    entryAction(context);  // ✅ Now runs after construction
    std::cout << "gothere" << std::endl;
    setTimer(15, context);  // ✅ Now safe to start the timer

}
void PedestriansFlash::timeout(Context& context)
{
    context.changeState(std::make_unique<VehiclesEnabled>("VehiclesEnabled", context));
}

