//
// Created by atcjw on 2/25/2025.
//

#ifndef STATE_H
#define STATE_H

class Context;

class State{
    public:
        virtual ~State() = default;

        virtual void timeout(Context& context) = 0;
        virtual void pedestrianWaiting(Context& context) = 0;

};
#endif //STATE_H
