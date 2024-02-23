#pragma once
#include "Point2D.h"

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
private:
	void pickup();

	Point2D m_location;
	int m_item;
	int m_type;
};

