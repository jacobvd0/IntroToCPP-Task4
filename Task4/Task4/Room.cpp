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
	std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;
	//std::cout << CSI << MAX_MAP_HEIGHT + 3 << ";" << 1 << "H";

	switch (m_type) {
	case EMPTY:
		std::cout << "It's an empty room, nothing to see here.\n";
		break;
	case ENEMY:
		std::cout << "WATCH OUT! An enemy is nearby.\n";
		break;
	case ITEM:
		std::cout << "It looks like there's a chest here.\n";
		break;
	case ITEM_DROPPED:
		std::cout << "You left something here earlier.\n";
		break;
	case ENTER:
		std::cout << "You came in this way, it seems to be blocked off.\n";
		break;
	case EXIT:
		std::cout << "You found the exit to go to the next floor!\n";
		break;
	}
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
