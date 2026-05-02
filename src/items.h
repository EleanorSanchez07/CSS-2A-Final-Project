#pragma once

#include <string>
#include "PhysicalGameObject.h"
#include "Player.h"

using namespace std;

class Item : public PhysicalGameObject
{
private:
    string itemName;
    bool collected;

public:
    Item();
    Item(string name);

    void collect(Player& player);

    string getName();
    bool isCollected();
};
