#include "Item.h"

// default constructor
Item::Item()
{
    name = "Item";
    value = 0;
    position = {0, 0};
    collected = false;
}

// custom constructor
Item::Item(string name, int value, float x, float y)
{
    this->name = name;
    this->value = value;
    position = {x, y};
    collected = false;
}

// draw item
void Item::draw()
{
    if (!collected)
    {
        DrawCircle(position.x, position.y, 15, YELLOW);
    }
}

// mark as collected
void Item::collect()
{
    collected = true;
}

// getters
bool Item::isCollected()
{
    return collected;
}

Vector2 Item::getPosition()
{
    return position;
}

string Item::getName()
{
    return name;
}

