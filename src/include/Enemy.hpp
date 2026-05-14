#pragma once
#include <string>
#include "Player.hpp"
#include "./GlobalRefs.hpp"
#include "./HurtTrigger.hpp"
#include "./raylib/raylib-cpp.hpp"
using namespace std;
class Enemy
{
public:
	//Enemy();
	Enemy(raylib::Vector2* playerPosition, Player* player, raylib::Texture2D* texture);
	Enemy(raylib::Vector2* playerPosition, string enemyName,Player* player, raylib::Texture2D* texture); 

	void status(bool alive);
	void findPlayer(Vector2 playerPosition);
	void tick();
	void setEnemyName(string EnemyName);
	void setSpeed(double speed);
	void setDmg(double dmg);
	//these are subject to change
	void setPlayerPosition(Vector2 playerPosition);
	void setEnemyPosition(Vector2 enemyPosition);
	void setTargetPosition(Vector2 targetPosition);
	
	Vector2 getEnemyPosition() const;
	Vector2 getTargetPostion() const;
	Vector2 getPlayerPosition() const;
	string getEnemyName() const;
	double getSpeed() const;
	double getDmg() const;
	//Also subject to change
	// int getPlayerPosition();
	double getEnemyPosition();
	// friend bool operator ==(const PhysicalGameObject& one, const PhysicalGameObject two);
	// friend Enemy operator + (const Enemy& one, const Enemy & two);
	// Enemy& operator =(const Enemy& e);

private:
	raylib::Vector2 enemyPosition;
	raylib::Vector2 enemySize;
	// raylib::Vector2& targetPosition;
	raylib::Vector2& playerPosition;
	float speed = 2.0f;//float literal 2.0
	string EnemyName;

	double dmg;
	Player& player;
	raylib::Texture2D* texture;

	HurtTrigger enemyTrigger = HurtTrigger(enemyPosition, enemySize, -30, &player);
};
