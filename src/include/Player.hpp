#pragma once
#include "./PhysicalGameObject.hpp"
//PLACEHOLDER: #include "./Item.hpp"

class Player: public PhysicalGameObject {
    public:
        Player(raylib::Texture2D* _texture);
        Player(std::string name, raylib::Texture2D* _texture);

        std::string getName();
        bool getAlive();
        bool getWonState();
        //PLACEHOLDER: Item getItemByIndex(int index);

        void setName(std::string name);
        void setAlive(bool alive);
        void setHasWonState(bool hasWonState);
        //PLACEHOLDER: void setItemByIndex(int index, Item item);
        //PLACEHOLDER: void setItemByIndex(Item item, int index);

        void tick();
        void handleInput();
        //PLACEHOLDER: void grabItem(Item& item);
        
    private:
        std::string name;
        bool alive, hasWonState;
        //PLACEHOLDER: Item items[4] = {};

};