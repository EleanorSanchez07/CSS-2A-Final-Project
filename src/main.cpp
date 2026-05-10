#include "./include/raylib/raylib-cpp.hpp"
raylib::Window window(1280, 800, "Untitled Spooky Game");

#include "./include/GameObject.hpp"
#include "./include/PhysicalGameObject.hpp"
#include "./include/Trigger.hpp"
#include "./include/DisplayTextTrigger.hpp"
#include "./include/Player.hpp"
#include "./include/GlobalRefs.hpp"

#include <iostream>
#include <memory>

raylib::Texture2D TEX_NOTHING = raylib::Texture2D("resources/transparent.png");

raylib::Texture2D TEX_PLAYER = raylib::Texture2D("resources/glep.png");
raylib::Texture2D TEX_DARKNESS = raylib::Texture2D("resources/darkness.png");

std::vector<PhysicalGameObject> worldObstacles = std::vector<PhysicalGameObject>();

int numTriggersInWorld = 0;
Trigger* worldTriggers[maxTriggersInWorld];

std::vector<PhysicalGameObject> worldEnemies = std::vector<PhysicalGameObject>();

int main() {
    window.SetExitKey(0);
    
    Player player = Player(&TEX_PLAYER, &TEX_DARKNESS);
    player.setPosition(window.GetSize() / 2 - player.getSize() / 2);

    worldTriggers[numTriggersInWorld] = new DisplayTextTrigger({0, 300}, {128, 128}, "Hello World");
    numTriggersInWorld++;

    raylib::Color background = raylib::Color(0, 0, 0, 255);
    SetTargetFPS(60);
    
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
            { //empty scope between begin and end draw; makes code prettier :3
                player.tick();

                window.ClearBackground(background);
            }
        EndDrawing();
    }
    
    for(int i = 0; i < numTriggersInWorld; i++) {
        delete worldTriggers[i];
    }

    return 0;
}