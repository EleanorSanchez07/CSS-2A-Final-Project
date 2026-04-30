#pragma once
#include "raylib/raylib-cpp.hpp"
#include <PhysicalGameObject.hpp>
#include <vector>

class Room{
    public:
        Room();
        Room(vector<PhysicalGameObject> worldObstacles, vector<PhysicalGameObject> worldTrigger, 
            vector<PhysicalGameObject> worldEnemies);
        void addObstacle(PhysicalGameObject ob);
        void addTrigger(PhysicalGameObject tr);
        void addEnemy(PhysicalGameObject en);
        std::vector<PhysicalGameObject> Obstacles();
        std::vector<PhysicalGameObject> Triggers();
        std::vector<PhysicalGameObject> Enemies();
        raylib::Vector2 setPlayerPosition(raylib::Vector2 pPos);
    private:
        bool exists;
        std::vector<PhysicalGameObject> worldObstacles;
        std::vector<PhysicalGameObject> worldTriggers;
        std::vector<PhysicalGameObject> worldEnemies;
        raylib::Vector2 playerPos;
};