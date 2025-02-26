//
// Created by atcjw on 2/25/2025.
//

#ifndef PEDESTRIANS_WALK_H
#define PEDESTRIANS_WALK_H

#include "PedestriansEnabled.h"

class PedestriansWalk : public PedestriansEnabled {
public:
    void timeout(Context &context) override;
    void pedestrianWaiting(Context &context) override;
};

#endif // PEDESTRIANS_WALK_H

