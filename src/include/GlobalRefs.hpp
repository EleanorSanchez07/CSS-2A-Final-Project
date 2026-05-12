#pragma once
#include <memory>
#include "raylib/raylib-cpp.hpp"
#include "Room.hpp"
#include "PhysicalGameObject.hpp"
#include "Trigger.hpp"

extern raylib::Texture2D TEX_PLAYER;
extern raylib::Texture2D TEST_BG = raylib::Texture2D("resources/image2.png"); //TODO: Needs to be defined in main instead!

//create basic templates for room items
Room demoLevel[6][6];
// set up rooms
int loc[2];

extern raylib::Texture2D TEX_NOTHING;

extern raylib::Texture2D TEX_DARKNESS;

extern std::vector<PhysicalGameObject> worldObstacles;
// extern std::vector<std::shared_ptr<Trigger>> worldTriggers;

const int maxTriggersInWorld = 20;
extern int numTriggersInWorld;
extern Trigger* worldTriggers[maxTriggersInWorld];

extern std::vector<PhysicalGameObject> worldEnemies;

extern void reset();
