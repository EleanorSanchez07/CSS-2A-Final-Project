#include "./include/Player.hpp"

Player::Player(raylib::Texture2D* _texture): PhysicalGameObject(_texture) {
    this -> name = "Hero";
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

}

void Player::handleInput() {
    this -> setPosition(this -> getPosition() + this -> velocity);
    this -> collisionShape.SetPosition(this -> getPosition());

    this -> draw();
}

/*PLACEHOLDER: void grabItem(Item& item) {

}*/