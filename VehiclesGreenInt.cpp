//
// Created by atcjw on 2/25/2025.
//

#include "VehiclesGreenInt.h"
#include <memory>
#include "VehiclesYellow.h"
#include "Context.h"

void VehiclesGreenInt::timeout(Context &context) {
    std::cout << "VehiclesGreenInt: Transitioning to VehiclesYellow.\n";
    context.setState(std::make_unique<VehiclesYellow>());
}