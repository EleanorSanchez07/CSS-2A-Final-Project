#pragma once
#include "raylib/raylib-cpp.hpp"
#include "Room.hpp"

extern raylib::Texture2D TEX_PLAYER = raylib::Texture2D("resources/glep.png");
extern raylib::Texture2D TEST_BG = raylib::Texture2D("resources/image2.png");


//create basic templates for room items
Room demoLevel[6][6];
// set up rooms
int loc[2];