#pragma once
#include "Point2D.h"
class Player;

class Room
{
public:
	Room();
	~Room();

	void setType(int type);
	int getType();

	void setItem(int item);
	int getItem();

	void draw();
	void drawDescription();

	void setPosition(Point2D pos);
	void executeCommand();

	void dealDamage(int dmg);
	void attackPlayer(Player& plr);

	int getEnemyHP();
	int getEnemyMaxHP();
private:
	void pickup();

	Point2D m_location;
	int m_item;
	int m_type;
	int m_enemyHP = 30;
	int m_maxHP = 30;
};

