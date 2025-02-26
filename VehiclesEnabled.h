//
// Created by atcjw on 2/25/2025.
//

#ifndef VEHICLESENABLED_H
#define VEHICLESENABLED_H
#include <iostream>
#include "State.h"


class VehiclesEnabled : public State {
    void pedestrianWaiting(Context &context) override;
};



#endif //VEHICLESENABLED_H
