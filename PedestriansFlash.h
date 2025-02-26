//
// Created by atcjw on 2/25/2025.
//

#ifndef PEDESTRIANSFLASH_H
#define PEDESTRIANSFLASH_H

#include "PedestriansEnabled.h"

class PedestriansFlash : public PedestriansEnabled {
private:
    int flashCounter = 7;

public:
    void timeout(Context &context) override;
    void pedestrianWaiting(Context& context) override;
};


#endif //PEDESTRIANSFLASH_H
