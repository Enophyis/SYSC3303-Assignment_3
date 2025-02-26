//
// Created by atcjw on 2/25/2025.
//

#ifndef VEHICLESYELLOW_H
#define VEHICLESYELLOW_H
#include "VehiclesEnabled.h"


class VehiclesYellow : public VehiclesEnabled
{
public:
    void timeout(Context& context) override;
};



#endif //VEHICLESYELLOW_H
