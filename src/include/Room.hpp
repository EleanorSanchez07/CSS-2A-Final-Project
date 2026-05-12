#pragma once
#include "raylib/raylib-cpp.hpp"
#include "PhysicalGameObject.hpp"
#include <vector>
using namespace std;

class Room{
    public:
        Room();
        Room(vector<PhysicalGameObject> worldObstacles, PhysicalGameObject *worldTriggers[20], 
            vector<PhysicalGameObject> worldEnemies, vector<PhysicalGameObject> worldObjects);
        void addObstacle(PhysicalGameObject ob);
        void addEnemy(PhysicalGameObject en);
        std::vector<PhysicalGameObject> Obstacles();
        PhysicalGameObject& Triggers();
        std::vector<PhysicalGameObject> Enemies();
        raylib::Vector2 setPlayerPosition(raylib::Vector2 pPos);
        void tick();
        bool Exists();
        void removeEnemy(PhysicalGameObject en);
        void removeItem(PhysicalGameObject i);
        void setWorldTriggers(PhysicalGameObject* wt[20]);
    private:
        bool exists;
        std::vector<PhysicalGameObject> worldObstacles;
        PhysicalGameObject* worldTriggers[20];
        std::vector<PhysicalGameObject> worldEnemies;
        std::vector<PhysicalGameObject> worldObjects;
        raylib::Vector2 playerPos;
};