//
// Created by atcjw on 2/25/2025.
//

#include "PedestriansFlash.h"
#include "VehiclesGreen.h"
#include "Context.h"

void PedestriansFlash::timeout(Context &context) {
    flashCounter--;
    if (flashCounter == 0) {
        std::cout << "PedestriansFlash: Transitioning to VehiclesGreen.\n";
        context.setState(std::make_unique<VehiclesGreen>());
    } else {
        std::cout << "PedestriansFlash: Flashing... " << flashCounter << " flashes left.\n";
    }
}

void PedestriansFlash::pedestrianWaiting(Context &context) {
    std::cout << "PedestriansFlash: Pedestrian waiting ignored, already in flashing state.\n";
}