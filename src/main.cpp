#include "./include/raylib/raylib-cpp.hpp"
raylib::Window window(1280, 800, "Testing this!");

#include "./include/GameObject.hpp"
#include "./include/PhysicalGameObject.hpp"
#include "./include/Room.hpp"
#include "./include/GlobalRefs.hpp"

#include <iostream>

//Basic structure taken from getting started guide 

void enterRoom(Room r);
void leaveRoom(Room& r);

std::vector<PhysicalGameObject> worldObstacles = std::vector<PhysicalGameObject>();
std::vector<PhysicalGameObject> worldTriggers = std::vector<PhysicalGameObject>();
std::vector<PhysicalGameObject> worldEnemies = std::vector<PhysicalGameObject>();

int main() {

    window.SetExitKey(0);


    PhysicalGameObject player = PhysicalGameObject(&TEX_PLAYER);
    player.setPosition(raylib::Vector2(window.GetWidth() / 2 - player.getSize().x / 2, window.GetHeight() / 2 - player.getSize().y / 2));

    raylib::Color background = raylib::Color(255, 0, 0, 255);
    SetTargetFPS(60);
    loc[0]=3;
    loc[1]=3;
    
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
            { //empty scope between begin and end draw; makes code pretty :3
                window.ClearBackground(background);
                player.tick();
                demoLevel[loc[0]][loc[1]].tick();
            }
        EndDrawing();
    }
 
    return 0;
}

/*
//no longer needed
void enterRoom(Room r){
    // pulls out the vectors
    worldObstacles = r.Obstacles();
    worldTriggers = r.Triggers();
    worldEnemies = r.Enemies();
}
void leaveRoom(Room& r){
    // unsure if this is neccesary
    // sets the vectors to empty vectors
    r.setEnemies(worldEnemies);
    worldObstacles = std::vector<PhysicalGameObject>();
    worldTriggers = std::vector<PhysicalGameObject>();
    worldEnemies = std::vector<PhysicalGameObject>();
}
*/