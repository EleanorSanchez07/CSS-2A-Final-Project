#pragma once
#include "GameObject.hpp"
#include "raylib/raylib-cpp.hpp"

class PhysicalGameObject: public GameObject {
    public:
        PhysicalGameObject(raylib::Texture2D* _texture);
        void tick();

        void setVelocity(raylib::Vector2 velocity);
        void setVelocityX(double velocity);
        void setVelocityY(double velocity);

        raylib::Vector2 getVelocity();
    private:
        raylib::Vector2 velocity;
        raylib::Rectangle collisionShape;
};