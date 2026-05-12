#include "items.h"

// default constructor
Item::Item(raylib::Texture2D* texture)
    : GameObject(texture)
{
}

// constructor with values
Item::Item(std::string name,
           raylib::Vector2 position,
           raylib::Texture2D* texture)
    : GameObject(texture)
{
    itemName = name;
    itemPosition = position;
}


void Item::Draw()
{
    
}
