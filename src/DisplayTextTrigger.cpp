#include "./include/DisplayTextTrigger.hpp"

DisplayTextTrigger::DisplayTextTrigger(raylib::Vector2 position, raylib::Vector2 size, std::string message): Trigger(position, size) {
    this -> message = message;
}

void DisplayTextTrigger::activate() {
    raylib::DrawText(message, 0, 0, 24, {255, 255, 255, 255});
}