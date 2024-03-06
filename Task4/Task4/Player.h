#pragma once
#include "Point2D.h"
//#include "OldSword.h"
#include "Room.h"

class Player
{
public:
	Player();
	Player(Point2D pos);
	Player(int x, int y);
	~Player();

	Point2D GetPosition();
	void SetPosition(Point2D pos);
	void draw();
	void useItem(int item, Room& room, Player& plr);
	bool pickup(int item);
private:
	Point2D m_playerPos;
	int m_inventory[5];
	int m_health = 100;
	int m_maxhealth = 30;

	//OldSword m_oldsword; // this is the only item stored here since it has a durability
};

