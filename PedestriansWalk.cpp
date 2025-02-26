//
// Created by atcjw on 2/25/2025.
//

#include "PedestriansWalk.h"
#include <iostream>
#include "Context.h"
#include "PedestriansFlash.h"

void PedestriansWalk::timeout(Context &context) {
    std::cout << "PedestriansWalk: Transitioning to PedestriansFlash.\n";
    context.setState(std::make_unique<PedestriansFlash>());
}

void PedestriansWalk::pedestrianWaiting(Context &context) {
    std::cout << "PedestriansWalk: Pedestrian already walking, no need to wait again.\n";
}