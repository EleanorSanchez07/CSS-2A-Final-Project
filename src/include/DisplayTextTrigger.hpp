#pragma once
#include "Trigger.hpp"

class DisplayTextTrigger: public Trigger {
    public:
        DisplayTextTrigger(raylib::Vector2 position, raylib::Vector2 size, std::string message);
        virtual void activate();
    protected:
        std::string message;
};