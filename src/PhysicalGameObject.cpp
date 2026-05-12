#include "include/PhysicalGameObject.hpp"

PhysicalGameObject::PhysicalGameObject(raylib::Texture2D* _texture): GameObject(_texture) {
    this -> velocity = raylib::Vector2(0, 0);
    this -> collisionShape = raylib::Rectangle(this -> getPosition(), this -> getSize());
}

void PhysicalGameObject::tick() {
    this -> setPosition(this -> getPosition() + this -> velocity);
    this -> collisionShape.SetPosition(this -> getPosition());

    this -> draw();
}

void PhysicalGameObject::setVelocity(raylib::Vector2 velocity) {
    this -> velocity = velocity;
}

void PhysicalGameObject::setVelocityX(double velocity) {
    this -> velocity.x = velocity;
}

void PhysicalGameObject::setVelocityY(double velocity) {
    this -> velocity.y = velocity;
}

raylib::Vector2 PhysicalGameObject::getVelocity() {
    return this -> velocity;
}

bool operator ==(const PhysicalGameObject& one, const PhysicalGameObject two){
    // this is just to get it to shut up, this needs to be implemented for
    // the enemy class
    return true;
}