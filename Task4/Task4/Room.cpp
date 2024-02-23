#include "Room.h"
#include "GameDefines.h"

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
}

void Room::drawDescription()
{
}

void Room::setPosition()
{
}

void Room::executeCommand()
{
}

void Room::pickup()
{
}
