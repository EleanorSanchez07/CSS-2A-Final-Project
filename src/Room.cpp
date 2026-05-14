#include "./include/Room.hpp"
using namespace std;

Room::Room(){
    // just for unused rooms in the level 2d array
    exists = false;
}

Room::Room(/*vector<PhysicalGameObject> worldObstacles, RoomChangeTrigger *wt[4],*/ 
vector<Enemy> worldEnemies, vector<Item> worldObjects){
    exists = true;
    //this->worldObstacles = worldObstacles;
    //setWorldTriggers(wt);
    this->worldEnemies = worldEnemies;
    this->worldObjects = worldObjects;

    playerPos = raylib::Vector2(0, 0);
}

/*
void Room::setWorldTriggers(RoomChangeTrigger* wt[4]){
    for(int i = 0; i<4; i++){
        *worldTriggers[i] = *wt[i];
    }
}


void Room::addObstacle(PhysicalGameObject ob){
    worldObstacles.push_back(ob);
}
*/

void Room::addEnemy(Enemy en){
    worldEnemies.push_back(en);
}

/*
std::vector<PhysicalGameObject> Room::Obstacles(){
    return worldObstacles;
}
*/

std::vector<Item> Room::Objects(){
    return worldObjects;
}


std::vector<Enemy> Room::Enemies(){
    return worldEnemies;
}

void Room::setPlayerPosition(raylib::Vector2 pPos){
    playerPos = pPos;
}

void Room::tick(){
    /*
    for(PhysicalGameObject ob : worldObstacles){
        ob.tick();
    }
    */
    for(Enemy ob : worldEnemies){
        ob.tick();
    }
    for(Item ob : worldObjects){
        //ob.tick();
    }
}

/*
void Room::removeEnemy(Enemy en){
    for (std::vector<Enemy>::iterator it = worldEnemies.begin(); it != worldEnemies.end();)
    {
        // if (*it == en)
        if(true)
            it = worldEnemies.erase(it);
    }
}
*/

bool Room::Exists(){
    return exists;
}
