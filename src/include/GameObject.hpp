#pragma once
#include "./raylib/raylib-cpp.hpp"

class GameObject {
    public:
        GameObject(raylib::Texture2D* _texture);
        // GameObject& operator = (GameObject& gameObject);

        raylib::Vector2 getPosition();
        raylib::Vector2 getSize();

        void setPosition(raylib::Vector2 position);
        void setSize(raylib::Vector2 size);

        void draw();

        // void Update();
    protected:
        raylib::Texture2D* texture;
        raylib::Vector2 position;
        raylib::Vector2 size;
};