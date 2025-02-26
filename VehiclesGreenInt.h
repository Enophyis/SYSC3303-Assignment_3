//
// Created by atcjw on 2/25/2025.
//

#ifndef VEHICLESGREENINT_H
#define VEHICLESGREENINT_H
#include "VehiclesGreen.h"


class VehiclesGreenInt : public VehiclesEnabled
{
    public:
    void timeout(Context &context) override;

};



#endif //VEHICLESGREENINT_H
