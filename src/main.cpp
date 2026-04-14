#include "./include/raylib/raylib-cpp.hpp"
#include <iostream>

//Basic structure taken from getting started guide 

int main() {
    raylib::Window window(1280, 800, "Testing this!");
    window.SetExitKey(0);

    raylib::Image img = raylib::LoadImage("resources/glep.png");
    raylib::Texture2D player = raylib::Texture2D(img);
    player.width = 128;
    player.height = 128;

    raylib::Vector2 position = raylib::Vector2(window.GetWidth() / 2 - player.GetWidth() / 2, window.GetHeight() / 2 - player.GetHeight() / 2);
    raylib::Vector2 velocity = raylib::Vector2(0, 0);

    raylib::Color background = raylib::Color(255, 0, 0, 255);
    SetTargetFPS(60);
    
    // Main game loop
    while (!window.ShouldClose()) {   //Check if close button pressed on window.
        BeginDrawing();
        {
            velocity = raylib::Vector2(0, 0);

            if(IsKeyDown(KEY_W)) {
                velocity.y = -10;
            } else if (IsKeyDown(KEY_S)) {
                velocity.y = 10;
            }

            if(IsKeyDown(KEY_A)) {
                velocity.x = -10;
            } else if (IsKeyDown(KEY_D)) {
                velocity.x = 10;
            }

            velocity = velocity.Normalize() * 10;

            position += velocity;

            player.Draw(position); //Drawing "player" in center of screen.
            window.ClearBackground(background); //Erases everything to draw the next frame.
        } //Brackets to clearly indicate where the drawing starts and ends using a new scope.
        EndDrawing();
    }
 
    return 0;
}