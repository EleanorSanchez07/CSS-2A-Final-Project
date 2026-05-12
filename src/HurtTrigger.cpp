#include <iostream>
#include "./include/HurtTrigger.hpp"

HurtTrigger::HurtTrigger(raylib::Vector2 position, raylib::Vector2 size, int healthEffect, Player& player): player(player), Trigger(position, size) {
    this -> healthEffect = healthEffect;
}

void HurtTrigger::activate() {
    this -> player.changeHealth(this -> healthEffect);
    std::cout << "Changed player health by " << this -> healthEffect << ".\n";
}