#include "Room.hpp"
using namespace std;

Room::Room(){
    // just for unused rooms in the level 2d array
    exists = false;
}

Room::Room(vector<PhysicalGameObject> worldObstacles, PhysicalGameObject *wt[20], 
vector<PhysicalGameObject> worldEnemies, vector<PhysicalGameObject> worldObjects){
    exists = true;
    this->worldObstacles = worldObstacles;
    setWorldTriggers(wt);
    this->worldEnemies = worldEnemies;
    this->worldObjects = worldObjects;

    playerPos = raylib::Vector2(0, 0);
}

void Room::setWorldTriggers(PhysicalGameObject* wt[20]){
    for(int i = 0; i<20; i++){
        *worldTriggers[i] = *wt[i];
    }
}

void Room::addObstacle(PhysicalGameObject ob){
    worldObstacles.push_back(ob);
}

void Room::addEnemy(PhysicalGameObject en){
    worldEnemies.push_back(en);
}

std::vector<PhysicalGameObject> Room::Obstacles(){
    return worldObstacles;
}

/*PhysicalGameObject& Room::Triggers(){
    return worldTriggers;
}
// needs to be functional but ughhh
*/

std::vector<PhysicalGameObject> Room::Enemies(){
    return worldEnemies;
}

raylib::Vector2 Room::setPlayerPosition(raylib::Vector2 pPos){
    playerPos = pPos;
}

void Room::tick(){
    for(int i = 0; i<20; i++){
        worldTriggers[i]->tick();
    }
    for(PhysicalGameObject ob : worldObstacles){
        ob.tick();
    }
    for(PhysicalGameObject ob : worldEnemies){
        ob.tick();
    }
    for(PhysicalGameObject ob : worldObjects){
        ob.tick();
    }
}

void Room::removeEnemy(PhysicalGameObject en){
    for (std::vector<PhysicalGameObject>::iterator it = worldEnemies.begin(); it != worldEnemies.end();)
    {
        if (*it == en)
            it = worldEnemies.erase(it);
    }
}

bool Room::Exists(){
    return exists;
}
