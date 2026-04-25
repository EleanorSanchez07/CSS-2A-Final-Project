#include "Room.hpp"
using namespace std;

Room::Room(){
    exists = false;
}
Room::Room(bool exists){
    this->exists = exists;
}
void Room::enterRoom(){

}
void Room::leaveRoom(){

}
void Room::addObject(GameObject ob){
    gameObjects.push_back(ob);
}