#include <iostream>
#include <typeinfo>
#include "./include/GlobalRefs.hpp"
#include "./include/Player.hpp"

const float INTERACTION_RADIUS = 180.0;

Player::Player(raylib::Texture2D* _texture, raylib::Texture2D* _texture_darkness): PhysicalGameObject(_texture) {
    this -> size = raylib::Vector2(128, 128);
    this -> collisionShape.SetSize(this -> size);
    this -> interactionCircle = Circle(this -> position, INTERACTION_RADIUS);

    for(std::string str : this -> items) str = "";

    this -> alive = true;
    this -> hasWonState = false;

    this -> darknessTexture = _texture_darkness;
}

bool Player::getAlive() {
    return this -> alive;
}

bool Player::getWonState() {
    return this -> hasWonState;
}

/*PLACEHOLDER: Item& Player::getItemByIndex(int index) {
    return this -> items[index];
}*/

void Player::setAlive(bool alive) {
    this -> alive = alive;
}

void Player::setHasWonState(bool hasWonState) {
    this -> hasWonState = hasWonState;
}

void Player::setItemByIndex(int index, std::string item) {
    this -> items[index] = item;
}

void Player::setItemByIndex(std::string item, int index) {
    this -> items[index] = item;
}

void Player::draw() {
    GameObject::draw();

    raylib::Vector2 darknessPosition = raylib::Vector2(this -> position) - raylib::Vector2(1536 - 64, 1024 - 64);
    darknessTexture -> Draw(darknessPosition);

    // this -> collisionShape.Draw({255, 0, 0, 100}); //Debug player collision shape.
}

void Player::tick() {
    this -> setVelocity(raylib::Vector2(0, 0));
    this -> handleInput();
    this -> checkTriggers();

    this -> setPosition(this -> getPosition() + this -> velocity);
    this -> interactionCircle = Circle(this -> position + this -> size / 2, INTERACTION_RADIUS);
    this -> collisionShape.SetPosition(this -> getPosition());

    // this -> position.DrawCircle(10);
    this -> draw();
}

void Player::handleInput() {
    raylib::Vector2 enemyPos = {120, 120};
    raylib::Vector2 playerPos = {200, 200};

    raylib::Vector2 enemyVelocity = playerPos - enemyPos;

    if(raylib::Keyboard::IsKeyDown(KEY_W) || raylib::Keyboard::IsKeyDown(KEY_UP)) {
        this -> setVelocityY(-10);
    } else if(raylib::Keyboard::IsKeyDown(KEY_S) || raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
        this -> setVelocityY(10);
    }

    if(raylib::Keyboard::IsKeyDown(KEY_A) || raylib::Keyboard::IsKeyDown(KEY_LEFT)) {
        this -> setVelocityX(-10);
    } else if(raylib::Keyboard::IsKeyDown(KEY_D) || raylib::Keyboard::IsKeyDown(KEY_RIGHT)) {
        this -> setVelocityX(10);
    }
}

void Player::checkTriggers() {
    for (int i = 0; i < numTriggersInWorld; i++) {
        // Trigger trigger = *(worldTriggers[i]); //Need to make a variable like this to dereference the trigger. Fucking diabolical.
        if(this -> collisionShape.CheckCollision(worldTriggers[i] -> getCollisionShape())) {
            worldTriggers[i] -> activate();
        }
    }
}