//
// Created by atcjw on 2/25/2025.
//

#include "Context.h"
#include "VehiclesGreen.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Initialize the state machine with VehiclesGreen as the starting state
    Context pedestrianSystem(std::make_unique<VehiclesGreen>());

    std::cout << "🚦 Pedestrian Crossing State Machine Simulation 🚦\n";
    std::cout << "--------------------------------------------\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[EVENT] Pedestrian presses the button\n";
    pedestrianSystem.pedestrianWaiting();

    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "[EVENT] Timeout for green -> yellow transition\n";
    pedestrianSystem.timeout();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "[EVENT] Timeout for yellow -> red transition\n";
    pedestrianSystem.timeout();

    std::this_thread::sleep_for(std::chrono::seconds(15));
    std::cout << "[EVENT] Timeout for pedestrian walk -> flashing\n";
    pedestrianSystem.timeout();

    for (int i = 0; i < 7; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "[EVENT] Flashing countdown " << (7 - i) << "\n";
        pedestrianSystem.timeout();
    }

    std::cout << "[EVENT] Flashing complete, back to Vehicles Green\n";
    std::cout << "✅ Simulation complete!\n";

    return 0;
}
