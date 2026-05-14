#include <iostream>
#include <typeinfo>
#include "./include/GlobalRefs.hpp"
#include "./include/Player.hpp"

const float INTERACTION_RADIUS = 180.0;

// Player::Player(raylib::Texture2D* _texture, raylib::Texture2D* _texture_darkness): PhysicalGameObject(_texture) {
//     this -> size = raylib::Vector2(128, 128);
//     this -> collisionShape.SetSize(this -> size);
//     this -> interactionCircle = Circle(this -> position, INTERACTION_RADIUS);

//     for(std::string str : this -> items) str = "";

//     this -> alive = true;
//     this -> hasWonState = false;

//     this -> health = 20;

//     this -> darknessTexture = _texture_darkness;
// }

Player::Player(): PhysicalGameObject(&TEX_PLAYER) {
    this -> size = raylib::Vector2(128, 128);
    this -> collisionShape.SetSize(this -> size);
    this -> interactionCircle = Circle(this -> position, INTERACTION_RADIUS);

    for(std::string str : this -> items) str = "";

    this -> alive = true;
    this -> hasWonState = false;

    this -> health = 20;

    this -> texRegionOffset = raylib::Vector2(0, 0);

    this -> darknessTexture = &TEX_DARKNESS;
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

float Player::getHealth() {
    return this -> health;
}

void Player::setAlive(bool alive) {
    this -> alive = alive;
}

void Player::setHasWonState(bool hasWonState) {
    this -> hasWonState = hasWonState;
}

void Player::addItemToInventory(std::string item) {
    for(std::string i : this -> items) {
        if(i != "") {
            i = item;
            return;
        }
    }

    std::string message = "Player inventory is full, failed to add an item.";
    std::cout << message << std::endl;
    raylib::DrawText(message, 0, 0, 24, {255, 0, 0, 255});
}

void Player::setItemByIndex(int index, std::string item) {
    this -> items[index] = item;
}

void Player::setItemByIndex(std::string item, int index) {
    this -> items[index] = item;
}

void Player::setHealth(float health) {
    this -> health = health;
}

void Player::changeHealth(float healthEffect) {
    this -> health += healthEffect;
}

void Player::draw() {
    // this -> texture -> width = this -> size.x;
    // this -> texture -> height = this -> size.y;

    raylib::Rectangle regionRect = Rectangle();
    regionRect.SetSize(128, 120);
    regionRect.SetPosition(this -> texRegionOffset);

    DrawTextureRec(*this -> texture, regionRect, this -> position, {255, 255, 255, 255});
    // this -> texture -> DrawRect(this -> position);

    raylib::Vector2 darknessPosition = raylib::Vector2(this -> position) - raylib::Vector2(1536 - 64, 1024 - 64);
    darknessTexture -> Draw(darknessPosition);

    // this -> collisionShape.Draw({255, 0, 0, 100}); //Debug player collision shape.
}

void Player::tick() {
    if(this -> health <= 0) {
        reset();
    }

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
        this -> texRegionOffset.x = 128 * 2;
        this -> setVelocityY(-10);
    } else if(raylib::Keyboard::IsKeyDown(KEY_S) || raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
        this -> texRegionOffset.x = 128 * 0;
        this -> setVelocityY(10);
    }

    if(raylib::Keyboard::IsKeyDown(KEY_A) || raylib::Keyboard::IsKeyDown(KEY_LEFT)) {
        this -> texRegionOffset.x = 128 * 1;
        this -> setVelocityX(-10);
    } else if(raylib::Keyboard::IsKeyDown(KEY_D) || raylib::Keyboard::IsKeyDown(KEY_RIGHT)) {
        this -> texRegionOffset.x = 128 * 3;
        this -> setVelocityX(10);
    }
}

void Player::checkTriggers() {
    for (int i = 0; i < numTriggersInWorld; i++) {
        if(this -> collisionShape.CheckCollision(worldTriggers[i] -> getCollisionShape())) {
            worldTriggers[i] -> activate();
        }
    }
}