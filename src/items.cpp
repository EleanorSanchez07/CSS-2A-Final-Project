#include "items.h"

Item::Item() : PhysicalGameObject()
{
    itemName = "";
    collected = false;
}

Item::Item(string name) : PhysicalGameObject()
{
    itemName = name;
    collected = false;
}

string Item::getName()
{
    return itemName;
}

bool Item::isCollected()
{
    return collected;
}

void Item::collect(Player& player)
{
    for (int i = 0; i < 4; i++)
    {
        if (player.items[i] == "")
        {
            player.items[i] = itemName;
            collected = true;
            return;
        }
    }
}
