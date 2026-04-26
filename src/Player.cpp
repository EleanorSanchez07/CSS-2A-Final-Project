#include "./include/Player.hpp"

Player::Player(raylib::Texture2D* _texture): PhysicalGameObject(_texture) {
    this -> name = "Hero";
    this -> size = raylib::Vector2(64, 64);
}

Player::Player(std::string name, raylib::Texture2D* _texture): PhysicalGameObject(_texture) {
    this -> name = name;
}

std::string Player::getName() {
    return this -> name;
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

void Player::setName(std::string name) {
    this -> name = name;
}

void Player::setAlive(bool alive) {
    this -> alive = alive;
}

void Player::setHasWonState(bool hasWonState) {
    this -> hasWonState = hasWonState;
}

/*PLACEHOLDER: void Player::setItemByIndex(int index, Item item) {
    this -> items[index] = item;
}*/

/*PLACEHOLDER: void setItemByIndex(Item item, int index) {
    this -> items[index] = item;
}*/

void Player::tick() {
    this -> setVelocity(raylib::Vector2(0, 0));
    this -> handleInput();

    this -> setPosition(this -> getPosition() + this -> velocity);
    this -> collisionShape.SetPosition(this -> getPosition());

    this -> position.DrawCircle(10);
    this -> draw();
}

void Player::handleInput() {
    if(raylib::Keyboard::IsKeyDown(KEY_W)) {
        this -> setVelocityY(-10);
    } else if(raylib::Keyboard::IsKeyDown(KEY_S)) {
        this -> setVelocityY(10);
    }

    if(raylib::Keyboard::IsKeyDown(KEY_A)) {
        this -> setVelocityX(-10);
    } else if(raylib::Keyboard::IsKeyDown(KEY_D)) {
        this -> setVelocityX(10);
    }
}

/*PLACEHOLDER: void grabItem(Item& item) {

}*/