#pragma once
#include "raylib/raylib-cpp.hpp"
#include <GameObject.hpp>
#include <vector>

class Room{
    public:
        Room();
        Room(bool exists);
        void enterRoom();
        void leaveRoom();
        void addObject(GameObject ob);
    private:
        bool exists;
        std::vector<GameObject> gameObjects;
};