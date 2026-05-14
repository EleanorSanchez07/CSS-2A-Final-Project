#include "./include/raylib/raylib-cpp.hpp"
#include "./include/Enemy.hpp"
#include "./include/Player.hpp"
#include <iostream>
using namespace std;

//Enemy::Enemy()
//{
// 	EnemyName = "";
// 	speed = 0.0;
// 	dmg = 0.0;
//}
int thisIndex;
Enemy::Enemy(raylib::Vector2* playerPosition, Player* player, raylib::Texture2D* texture): player(*player), playerPosition(*playerPosition), texture(texture) //pass by reference 
{
//<<<<<<< HEAD
	enemyPosition = raylib::Vector2(-200, 0);
	enemySize = raylib::Vector2(100, 100);

	thisIndex = numTriggersInWorld;
	worldTriggers[thisIndex] = &enemyTrigger;
	numTriggersInWorld++;
	// this -> texture = &texture;
	// targetPosition = *playerPosition; //throws error because it can't assign an object of Vector2 to raylib::Vector2
	// double targetPosition = 0.0;
}
Enemy::Enemy(raylib::Vector2* playerPosition, string enemyName, Player* player, raylib::Texture2D* texture): player(*player), playerPosition(*playerPosition), texture(texture)
{
	enemyPosition = raylib::Vector2(0, 0);
	enemySize = raylib::Vector2(100, 100);
	// this -> texture = &texture;
	// playerPosition = 0.0;
	enemyName = "";
	// &player;
}
void Enemy::status(bool alive)
{
	this->player.setAlive(alive);
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
	// int velocity;
	// int object;
	// for (int i = 0; i < velocity; i++)
	// {
	// 	if (velocity++)
	// 	{
	// 		object = object + 1;
	// 	}
	// }

	// std::cout << "Hello world" << std::endl;

	// raylib::Vector2 _playerPosition = player.getPosition();

	raylib::Vector2 velocity = (playerPosition - enemyPosition);
	velocity = velocity.Normalize() * 2;

	this -> enemyPosition += velocity;

	worldTriggers[thisIndex] -> setCollisionShape({this -> enemyPosition, this -> enemySize});
	this -> texture -> Draw(this -> enemyPosition);
	// DrawTexture(*this -> texture, 0, 0, {255, 255, 255, 255});

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
void Enemy::setPlayerPosition(Vector2 playerPosition)
{
	// this->playerPosition = playerPosition;
}
void Enemy::setEnemyPosition(Vector2 enemyPosition) 
{
	this->enemyPosition = enemyPosition;
}
void Enemy::setTargetPosition(Vector2 targetPostion)
{
	// this -> playerPosition = targetPostion;
//=======
//>>>>>>> 66ed1d14fcb75a09608cf48c45bf32787c6e44f1
}
Vector2 Enemy::getPlayerPosition() const
{
	return playerPosition;
}
string Enemy::getEnemyName() const
{
	return EnemyName;
}
double Enemy::getSpeed() const
{
	return speed;
}
double Enemy::getDmg() const 
{
	return dmg;
}
// //== operator here
// bool operator ==(const Enemy& one, const Enemy two)
// {
// 	return true;
// }
// //+ operator here
// Enemy operator +(const Enemy& one, const Enemy & two) 
// {
// 	return two + one;
// }
// //= operator here

