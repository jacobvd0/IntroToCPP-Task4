#include "Room.h"
#include "GameDefines.h"
#include <iostream>

Room::Room()
{
	m_location = { 0,0 };
	m_item = AIR;
	m_type = EMPTY;
}

Room::~Room()
{
}

void Room::setType(int type)
{
	m_type = type;
}

int Room::getType()
{
	return m_type;
}

void Room::setItem(int item)
{
	m_item = item;
}

int Room::getItem()
{
	return m_item;
}

void Room::draw()
{
	switch (m_type) {
	case EMPTY:
		std::cout << EMPTY_ICON << " ";
		break;
	case ENEMY:
		std::cout << ENEMY_ICON << " ";
		break;
	case ITEM:
		std::cout << ITEM_ICON << " ";
		break;
	case ITEM_DROPPED:
		std::cout << ITEM_DROPPED_ICON << " ";
		break;
	case ENTER:
		std::cout << ENTER_ICON << " ";
		break;
	case EXIT:
		std::cout << EXIT_ICON << " ";
		break;
	}
}

void Room::drawDescription()
{
}

void Room::setPosition(Point2D pos)
{
}

void Room::executeCommand()
{
}

void Room::pickup()
{
}
