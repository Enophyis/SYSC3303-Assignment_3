//
// Created by atcjw on 2/25/2025.
//

#include "VehiclesYellow.h"
#include "PedestriansWalk.h"
#include "Context.h"

void VehiclesYellow::timeout(Context &context) {
    std::cout << "VehiclesYellow: Transitioning to PedestriansWalk.\n";
    context.setState(std::make_unique<PedestriansWalk>());
}
