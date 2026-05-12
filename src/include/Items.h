#pragma once

#include "GameObject.hpp"
#include <string>

class Item : public GameObject
{
private:
    std::string itemName;
    raylib::Vector2 itemPosition;

public:
    Item(raylib::Texture2D* texture);

    Item(std::string name,
         raylib::Vector2 position,
         raylib::Texture2D* texture);

    void Draw();
};
