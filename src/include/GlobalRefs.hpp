#pragma once
#include <memory>
#include "raylib/raylib-cpp.hpp"
#include "PhysicalGameObject.hpp"
#include "Trigger.hpp"

extern raylib::Texture2D TEX_NOTHING;

extern raylib::Texture2D TEX_PLAYER;
extern raylib::Texture2D TEX_DARKNESS;

extern std::vector<PhysicalGameObject> worldObstacles;
// extern std::vector<std::shared_ptr<Trigger>> worldTriggers;

const int maxTriggersInWorld = 20;
extern int numTriggersInWorld;
extern Trigger* worldTriggers[maxTriggersInWorld];

extern std::vector<PhysicalGameObject> worldEnemies;