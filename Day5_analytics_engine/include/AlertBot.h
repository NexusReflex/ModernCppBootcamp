#pragma once

#include <string>
#include <utility>
#include "ThreadedSubscriber.h"

class AlertBot : public Subscriber{
    public:
        explicit AlertBot(std::string name, int priority = 0) : Subscriber(std::move(name), priority){};
};