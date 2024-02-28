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
	std::cout << CSI << m_location.y + 1 << ";" << m_location.x * 4 + 2 << "H";

	switch (m_type) {
	case EMPTY:
		std::cout << GREY << "[" << RESET_COLOR << EMPTY_ICON << GREY << "] " << RESET_COLOR;
		break;
	case ENEMY:
		std::cout << GREY << "[" << RED << ENEMY_ICON << GREY << "] " << RESET_COLOR;
		break;
	case ITEM:
		std::cout << GREY << "[" << YELLOW << ITEM_ICON << GREY << "] " << RESET_COLOR;
		break;
	case ITEM_DROPPED:
		std::cout << GREY << "[" << RESET_COLOR << ITEM_DROPPED_ICON << GREY << "] " << RESET_COLOR;
		break;
	case ENTER:
		std::cout << GREY << "[" << LIGHT_GREY << ENTER_ICON << GREY << "] " << RESET_COLOR;
		break;
	case EXIT:
		std::cout << GREY << "[" << LIGHT_GREY << EXIT_ICON << GREY << "] " << RESET_COLOR;
		break;
	}
}

void Room::drawDescription()
{
}

void Room::setPosition(Point2D pos)
{
	m_location = pos;
}

void Room::executeCommand()
{
}

void Room::pickup()
{
}
