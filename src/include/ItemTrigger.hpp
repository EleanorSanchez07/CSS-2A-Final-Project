#pragma once
#include "Items.hpp"
#include "Trigger.hpp"

class ItemTrigger: public Trigger {
    public:
        ItemTrigger(raylib::Vector2 position, raylib::Vector2 size, Item& attachedItem);

        Item getItem();

        raylib::Vector2 getItemPosition();
        std::string getItemName;

        virtual void activate();
    private:
        Item& attachedItem;
};