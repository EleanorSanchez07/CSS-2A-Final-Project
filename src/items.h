#pragma once
#include "raylib.h"
#include <string>
using namespace std;

class Item
{
private:
    string name;
    int value;
    Vector2 position;
    bool collected;

public:
    // constructors
    Item();
    Item(string name, int value, float x, float y);

    // functions
    void draw();
    void collect();

    // getters
    bool isCollected();
    Vector2 getPosition();
    string getName();
};

