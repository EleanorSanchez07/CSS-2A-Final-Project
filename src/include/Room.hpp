#pragma once
#include "raylib/raylib-cpp.hpp"
#include "PhysicalGameObject.hpp"
#include "RoomChangeTrigger.hpp"
#include "Items.h"
#include "Enemy.h"
#include <vector>
using namespace std;

class Room{
    public:
        Room();
        Room(vector<PhysicalGameObject> worldObstacles, /*RoomChangeTrigger *worldTriggers[4],*/ 
            vector<Enemy> worldEnemies, vector<Item> worldObjects);
        void addObstacle(PhysicalGameObject ob);
        void addEnemy(Enemy en);
        std::vector<PhysicalGameObject> Obstacles();
        std::vector<Item> Objects();
        std::vector<Enemy> Enemies();
        raylib::Vector2 setPlayerPosition(raylib::Vector2 pPos);
        void tick();
        bool Exists();
        //void removeEnemy(Enemy en);
        //void removeItem(Item i);
        //void setWorldTriggers(RoomChangeTrigger* wt[4]);
    private:
        bool exists;
        std::vector<PhysicalGameObject> worldObstacles;
        //RoomChangeTrigger* worldTriggers[4];
        std::vector<Enemy> worldEnemies;
        std::vector<Item> worldObjects;
        raylib::Vector2 playerPos;
};