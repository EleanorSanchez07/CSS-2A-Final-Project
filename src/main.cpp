#include "./include/raylib/raylib-cpp.hpp"
raylib::Window window(1280, 800, "Testing this!");

#include "./include/GameObject.hpp"
#include "./include/PhysicalGameObject.hpp"
#include "./include/Room.hpp"
#include "./include/GlobalRefs.hpp"

#include <iostream>

//Basic structure taken from getting started guide 

void enterRoom(Room r);
void leaveRoom();

std::vector<PhysicalGameObject> worldObstacles = std::vector<PhysicalGameObject>();
std::vector<PhysicalGameObject> worldTriggers = std::vector<PhysicalGameObject>();
std::vector<PhysicalGameObject> worldEnemies = std::vector<PhysicalGameObject>();

int main() {
    /*
    //theoretical level setup
    Room level1[10][10];
    level1[5][5] = Room(true);
    */
    window.SetExitKey(0);


    PhysicalGameObject player = PhysicalGameObject(&TEX_PLAYER);
    player.setPosition(raylib::Vector2(window.GetWidth() / 2 - player.getSize().x / 2, window.GetHeight() / 2 - player.getSize().y / 2));

    raylib::Color background = raylib::Color(255, 0, 0, 255);
    SetTargetFPS(60);
    
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
            { //empty scope between begin and end draw; makes code pretty :3
                window.ClearBackground(background);
            }
        EndDrawing();
    }
 
    return 0;
}

void enterRoom(Room r){
    // pulls out the vectors
    worldObstacles = r.Obstacles();
    worldTriggers = r.Triggers();
    worldEnemies = r.Enemies();
}
void leaveRoom(){
    // unsure if this is neccesary
    // sets the vectors to empty vectors
    worldObstacles = std::vector<PhysicalGameObject>();
    worldTriggers = std::vector<PhysicalGameObject>();
    worldEnemies = std::vector<PhysicalGameObject>();
}