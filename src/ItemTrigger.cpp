#include "./include/Player.hpp"
#include "./include/ItemTrigger.hpp"

ItemTrigger::ItemTrigger(raylib::Vector2 position, raylib::Vector2 size, Item& attachedItem): attachedItem(attachedItem), Trigger(position, size) {};

void ItemTrigger::activate() {
    // Waiting on this functionality
    // Player& pl = this -> getItem().getPlayer();
}
