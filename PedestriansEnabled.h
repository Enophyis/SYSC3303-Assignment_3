//
// Created by atcjw on 2/25/2025.
//

#ifndef PEDESTRIANSENABLED_H
#define PEDESTRIANSENABLED_H
#include "State.h"


class PedestriansEnabled : public State
{
public:
    void timeout(Context& context) override;
};



#endif //PEDESTRIANSENABLED_H
