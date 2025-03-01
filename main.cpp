// Created by atcjw on 2/25/2025.

#include "Context.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {

    std::cout << "\nPedestrian Crossing State Machine Simulation\n";
    std::cout << "--------------------------------------------\n";
    Context intersection(std::make_unique<VehiclesEnabled>("VehiclesEnabled",intersection));
    intersection.printState();

    while (true)
    {
        // Initialize the state machine with VehiclesGreen as the starting state
        intersection.printState();
        std::cout << "[EVENT] Pedestrian presses the button\n";
        intersection.pedestrianWaiting();

        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout << "[EVENT] Timeout for green -> yellow transition\n";
        intersection.timeout();

        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "[EVENT] Timeout for yellow -> red transition\n";
        intersection.timeout();

        std::this_thread::sleep_for(std::chrono::seconds(15));
        std::cout << "[EVENT] Timeout for pedestrian walk -> flashing\n";
        intersection.timeout();

        for (int i = 0; i < 7; i++) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "[EVENT] Flashing countdown " << (7 - i) << "\n";
            intersection.timeout();
        }

        std::cout << "[EVENT] Flashing complete, back to Vehicles Green\n";
    }
    return 0;
}
