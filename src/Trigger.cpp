#include <iostream>
#include "./include/Trigger.hpp"
#include "./include/GlobalRefs.hpp"

Trigger::Trigger(): PhysicalGameObject(&TEX_NOTHING) {
    std::cout << "Useless trigger created. This probably isn't helpful" << std::endl;
};


Trigger::Trigger(raylib::Vector2 position, raylib::Vector2 size): PhysicalGameObject(&TEX_NOTHING) {
    this -> position = position;
    this -> size = size;

    this -> collisionShape = raylib::Rectangle(this -> position, this -> size);
};

void Trigger::activate() {
    std::cout << "Base trigger class used." << std::endl;
}