#pragma once
#include "./PhysicalGameObject.hpp"
//PLACEHOLDER: #include "./Item.hpp"

struct Circle {
    double x, y, radius;
    
    Circle() {
        this -> x = 0;
        this -> y = 0;
        this -> radius = 1;
    }

    Circle(raylib::Vector2 position, double radius) {
        this -> x = position.x;
        this -> y = position.y;
        this -> radius = radius;
    }

    Circle(double x, double y, double radius) {
        this -> x = x;
        this -> y = y;
        this -> radius = radius;
    }

    Circle(double radius) {
        this -> x = 0;
        this -> y = 0;
        this -> radius = radius;
    }
};

class Player: public PhysicalGameObject {
    public:
        Player(raylib::Texture2D* _texture, raylib::Texture2D* _texture_darkness);
        Player(std::string name, raylib::Texture2D* _texture, raylib::Texture2D* _texture_darkness);

        std::string getName();
        bool getAlive();
        bool getWonState();
        std::string getItemByIndex(int index);

        void setName(std::string name);
        void setAlive(bool alive);
        void setHasWonState(bool hasWonState);
        void setItemByIndex(int index, std::string item);
        void setItemByIndex(std::string item, int index);

        void tick();
        void handleInput();
        void draw();
        
    private:
        raylib::Texture2D* darknessTexture;
        Circle interactionCircle;
        std::string name;
        bool alive, hasWonState;
        std::string items[4];
};