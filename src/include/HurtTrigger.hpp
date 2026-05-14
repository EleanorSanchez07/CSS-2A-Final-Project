#pragma once
#include "Player.hpp"
#include "Trigger.hpp"

class HurtTrigger: public Trigger {
    public:
        HurtTrigger(raylib::Vector2 position, raylib::Vector2 size, int healthEffect, Player* player);
        virtual void activate();
    protected:
        int healthEffect;
        Player& player;
};