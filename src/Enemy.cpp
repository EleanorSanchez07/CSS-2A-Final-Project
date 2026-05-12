#include "../include/raylib/raylib-cpp.hpp"
#include "Enemy.h"
#include "Player.hpp"
#include "Player.cpp"
#include <iostream>
using namespace std;

Enemy::Enemy()
{
	EnemyName = "";
	speed = 0.0;
	dmg = 0.0;
}
Enemy::Enemy(raylib::Vector2& playerPosition, Player& player)//pass by reference
{
	targetPosition = &playerPosition;
	double targetPosition = 0.0;
}
Enemy::Enemy(raylib::Vector2& playerPosition, string enemyName, Player& player)
{
	float playerPosition = 0.0;
	enemyName = "";
}
Enemy::Status(bool alive)
{
	this.player.setAlive(alive);
}
void Enemy::findPlayer(Vector2 playerPosition)
{
	//The Enemy tracks the player and finds them. (Moving towards the player)
	//direction from ememyPosition to playerPosition subtracts playerPosition from enemy Position
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Vector2 direction = Vector2Subtract(playerPosition, enemyPosition);
	float distance = Vector2Length(direction);
	//normalize is the positioning isn't too close
	if (distance > 0.1f) {
		//normalize direction
		direction = Vector2Normalize(direction);
		distance = 1;
		//move enemy toward player
		enemyPosition = Vector2Add(enemyPosition, Vector2Scale(direction, speed));
	}
}
void Enemy::tick()
{
	//updates the object(enemy?) every frame when the position (is position enemy position or player p gets increased by velocity 
	//{done}
	int velocity;
	Enemy object;
	for (int i = 0; i < velocity; i++)
	{
		if (velocity++)
		{
			object = object + 1;
		}
	}
}
void Enemy::setEnemyName(string EnemyName)
{
	this->EnemyName = EnemyName;
}
void Enemy::setSpeed(double speed)
{
	this->speed = speed;
}
void Enemy::setDmg(double dmg)
{
	this->dmg = dmg;
}
//Subject to change or exist
void Enemy::setPlayerPosition(int playerPosition)
{
	this->playerPosition = playerPosition;
}
void Enemy::setEnemyPosition(Vector2 enemyPosition) 
{
	this->ememyPosition = enemyPosition;
}
int Enemy::getPlayerPosition() const
{
	return playerPosition;
}
string Enemy::getEnemyName() const
{
	return EnemyName;
}
string Enemy::getSpeed() const
{
	return speed;
}
string Enemy::getDmg()const
{
	return dmg;
}

