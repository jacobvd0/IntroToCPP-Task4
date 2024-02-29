#pragma once
#include "Point2D.h"

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
private:
	Point2D m_playerPos;
};

