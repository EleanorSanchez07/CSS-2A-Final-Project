#include "./include/raylib/raylib-cpp.hpp"
raylib::Window window(1280, 800, "Untitled Spooky Game");

#include "./include/GameObject.hpp"
#include "./include/PhysicalGameObject.hpp"
#include "./include/Room.hpp"
#include "./include/Trigger.hpp"
#include "./include/DisplayTextTrigger.hpp"
#include "./include/Player.hpp"
#include "./include/GlobalRefs.hpp"

#include <iostream>
#include <memory>

int loc[2] = {};
Room demoLevel[6][6] = {};

raylib::Texture2D TEX_NOTHING = raylib::Texture2D("resources/transparent.png");
raylib::Texture2D TEST_BG = raylib::Texture2D("resources/image2.png");
raylib::Texture2D TEX_PLAYER = raylib::Texture2D("resources/glep.png");
raylib::Texture2D TEX_DARKNESS = raylib::Texture2D("resources/darkness.png");

std::vector<PhysicalGameObject> _worldObstacles = std::vector<PhysicalGameObject>();

int numTriggersInWorld = 0;
Trigger* worldTriggers[maxTriggersInWorld] = {};
Trigger* _worldTriggers[maxTriggersInWorld];

std::vector<PhysicalGameObject> _worldEnemies = std::vector<PhysicalGameObject>();

Player player;

// void enterRoom(Room r);
// void leaveRoom(Room& r);

int main() {

    window.SetExitKey(0);
    
    player.setPosition(window.GetSize() / 2 - player.getSize() / 2);


    //PhysicalGameObject player = PhysicalGameObject(&TEX_PLAYER);
    //player.setPosition(raylib::Vector2(window.GetWidth() / 2 - player.getSize().x / 2, window.GetHeight() / 2 - player.getSize().y / 2));
    // worldTriggers[numTriggersInWorld] = new DisplayTextTrigger({0, 300}, {128, 128}, "Hello World");
    // numTriggersInWorld++;

    raylib::Color background = raylib::Color(0, 0, 0, 255);
    
    SetTargetFPS(60);
    loc[0]=3;
    loc[1]=3;
    
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
            { //empty scope between begin and end draw; makes code prettier :3
                player.tick();

                window.ClearBackground(background);
                demoLevel[loc[0]][loc[1]].tick();
            }
        EndDrawing();
    }
    
    for(int i = 0; i < numTriggersInWorld; i++) {
        delete _worldTriggers[i];
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
void reset() {
    for(int i = 0; i < numTriggersInWorld; i++) {
        delete _worldTriggers[i];
    }
    numTriggersInWorld = 0;

    player.setPosition(window.GetSize() / 2 - player.getSize() / 2);
    player.setHealth(10);
    _worldObstacles = std::vector<PhysicalGameObject>();
    numTriggersInWorld = 0;
    _worldEnemies = std::vector<PhysicalGameObject>();
    
    // worldTriggers[numTriggersInWorld] = new DisplayTextTrigger({0, 300}, {128, 128}, "Hello World");
    // numTriggersInWorld++;
}
