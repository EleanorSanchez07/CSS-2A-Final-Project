#include "./include/raylib/raylib-cpp.hpp"
#include <iostream>

//Basic structure taken from getting started guide 

int main() {
    raylib::Window window(1280, 800, "Testing this!");
    window.SetExitKey(0);

    raylib::Image img = raylib::LoadImage("resources/glep.png");
    raylib::Texture2D player = raylib::Texture2D(img);

    Color background = raylib::Color(255, 0, 0);
    SetTargetFPS(60);
 
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
        {
            player.Draw(window.GetWidth() / 2 - player.GetWidth() / 2, window.GetHeight() / 2 - player.GetHeight() / 2);
            window.ClearBackground(background); //Erases everything to draw the next frame.
        }
        EndDrawing();
    }
 
    return 0;
}