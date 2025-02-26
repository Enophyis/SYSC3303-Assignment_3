//
// Created by atcjw on 2/25/2025.
//

#include "VehiclesGreen.h"
#include <memory>
#include "VehiclesGreenInt.h"
#include "Context.h"

void VehiclesGreen::timeout(Context &context) {
    std::cout << "VehiclesGreen: Timeout occurred, transitioning...\n";
    context.setState(std::make_unique<VehiclesGreenInt>());
}

void VehiclesGreen::pedestrianWaiting(Context &context) {
    std::cout << "VehiclesGreen: Pedestrian pressed button.\n";
}