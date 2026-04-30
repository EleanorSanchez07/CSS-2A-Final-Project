#include "Room.hpp"
using namespace std;

Room::Room(){
    // just for unused rooms in the level 2d array
    exists = false;
}

Room::Room(vector<PhysicalGameObject> worldObstacles, vector<PhysicalGameObject> worldTriggers, 
vector<PhysicalGameObject> worldEnemies){
    exists = true;
    this->worldObstacles = worldObstacles;
    this->worldTriggers = worldTriggers;
    this->worldEnemies = worldEnemies;
    playerPos = raylib::Vector2(0, 0);
}

void Room::addObstacle(PhysicalGameObject ob){
    worldObstacles.push_back(ob);
}

void Room::addTrigger(PhysicalGameObject tr){
    worldTriggers.push_back(tr);
}

void Room::addEnemy(PhysicalGameObject en){
    worldEnemies.push_back(en);
}

std::vector<PhysicalGameObject> Room::Obstacles(){
    return worldObstacles;
}

std::vector<PhysicalGameObject> Room::Triggers(){
    return worldTriggers;
}

std::vector<PhysicalGameObject> Room::Enemies(){
    return worldEnemies;
}

raylib::Vector2 Room::setPlayerPosition(raylib::Vector2 pPos){
    playerPos = pPos;
}
