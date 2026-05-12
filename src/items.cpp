#include "./include/Items.h"
#include <cmath>

// default constructor
Item::Item(raylib::Texture2D* texture)
    : GameObject(texture)
{
}

// constructor 
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

void Item::Tick()
{
    itemPosition.y += sin(GetTime()) * 0.1f;
}

// getter for item
std::string Item::GetItemName()
{
    return itemName;
}

raylib::Vector2 Item::GetItemPosition()
{
    return itemPosition;
}

// setter for item name
void Item::SetItemName(std::string name)
{
    itemName = name;
}

// setter for item position
void Item::SetItemPosition(raylib::Vector2 position)
{
    itemPosition = position;
}
