#pragma once
#include<string>
#include "Player.hpp"
#include "../include/raylib/raylib-cpp.hpp"
using namespace std;
class Enemy
{
public:
	Enemy();
	Enemy(raylib::Vector2& playerPosition,Player& player);
	Enemy(raylib::Vector2& playerPosition, string enemyName,Player& player);
	void status(bool alive);
	void findPlayer(Vector2 playerPosition);
	void tick();
	void setEnemyName(string EnemyName);
	void setSpeed(double speed);
	void setDmg(double dmg);
	//these are subject to change
	void setPlayerPosition(int playerPosition);
	void setEnemyPosition(Vector2 enemyPosition);
	string getEnemyName() const;
	double getSpeed() const;
	double getdmg() const;
	//Also subject to change
	int getPlayerPosition()const;
	double getEnemyPosition();
	//friend Enemy operator + (const Enemy& v, const Enemy & o);
	//Enemy& operator =(const Enemy& e);

private:
	Vector2 enemyPosition;
	Vector2* targetPosition;
	Vector2* playerPosition;
	float speed = 2.0f;//float literal 2.0
	string EnemyName;
	double speed;
	double dmg;
	Player player&;
};
