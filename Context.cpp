#include "Context.h"

void Context::timeout() {
    currentState->timeout(*this);
}

void Context::pedestrianWaiting() {
    currentState->pedestrianWaiting(*this);
}
