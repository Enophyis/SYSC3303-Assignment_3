//
// Created by atcjw on 2/25/2025.
//

#ifndef VEHICLESGREEN_H
#define VEHICLESGREEN_H
#include "VehiclesEnabled.h"


class VehiclesGreen : public VehiclesEnabled {
public:
    void timeout(Context &context) override;
    void pedestrianWaiting(Context &context) override;
};

#endif //VEHICLESGREEN_H
