//
// Created by atcjw on 2/25/2025.
//

#include "PedestriansEnabled.h"
#include <iostream>
#include "Context.h"
#include "PedestriansWalk.h"

void PedestriansEnabled::timeout(Context &context) {
    std::cout << "PedestriansEnabled: Transitioning to PedestriansWalk.\n";
    context.setState(std::make_unique<PedestriansWalk>());
}
