#include "./include/GameObject.hpp"
#include <iostream>

GameObject::GameObject(raylib::Texture2D* _texture): texture(_texture) {
    this -> position = raylib::Vector2(0, 0);
    this -> size = raylib::Vector2(32, 32);
}

raylib::Vector2 GameObject::getPosition() {
    return this -> position;
}

raylib::Vector2 GameObject::getSize() {
    return this -> size;
}

void GameObject::setPosition(raylib::Vector2 position) {
    this -> position = position;
}

void GameObject::setSize(raylib::Vector2 size) {
    this -> size = size;
}

void GameObject::draw() {
    this -> texture -> width = this -> size.x;
    this -> texture -> height = this -> size.y;
    this -> texture -> Draw(this -> position);
}

// void GameObject::Update() {
//     // raylib::Texture2D texture = raylib::Texture2D(this -> texturePath);
//     // texture.width = (this -> size).x;
//     // texture.height = (this -> size).y;

//     // texture.Draw(this -> position);
// }