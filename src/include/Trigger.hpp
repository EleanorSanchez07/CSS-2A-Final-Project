#pragma once
#include "PhysicalGameObject.hpp"

class Trigger: public PhysicalGameObject {
    public:
        Trigger();
        Trigger(raylib::Vector2 position, raylib::Vector2 size);
        
        virtual void activate();
};
