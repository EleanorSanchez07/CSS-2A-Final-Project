#include "./include/raylib/raylib-cpp.hpp"
raylib::Window window(1280, 800, "Untitled Spooky Game");

#include "./include/GameObject.hpp"
#include "./include/PhysicalGameObject.hpp"
#include "./include/Player.hpp"
#include "./include/GlobalRefs.hpp"

#include <iostream>

//Basic structure taken from getting started guide 

int main() {
    window.SetExitKey(0);

    std::vector<PhysicalGameObject> worldObstacles = std::vector<PhysicalGameObject>();
    std::vector<PhysicalGameObject> worldTriggers = std::vector<PhysicalGameObject>();
    std::vector<PhysicalGameObject> worldEnemies = std::vector<PhysicalGameObject>();

    Player player = Player(&TEX_PLAYER);
    player.setPosition(window.GetSize() / 2 - player.getSize() / 2);

    raylib::Color background = raylib::Color(128, 128, 128, 255);
    SetTargetFPS(60);
    
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
            { //empty scope between begin and end draw; makes code pretty :3
                player.tick();

                window.ClearBackground(background);
            }
        EndDrawing();
    }
 
    return 0;
}