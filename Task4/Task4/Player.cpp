#include "Player.h"
#include "GameDefines.h"
#include <iostream>

Player::Player()
{
	m_playerPos = Point2D{0,0};
}

Player::Player(Point2D pos)
{
	m_playerPos = pos;
}

Player::Player(int x, int y)
{
	m_playerPos = Point2D{ x, y };
}

Player::~Player()
{
}

Point2D Player::GetPosition()
{
	return m_playerPos; 
}

void Player::SetPosition(Point2D pos)
{
	m_playerPos = pos;
}

void Player::draw()
{
	std::cout << CSI << m_playerPos.y + 1 << ";" << m_playerPos.x * 4 + 2 << "H";

	std::cout << GREY << "[" << GREEN << PLAYER_ICON << GREY << "] " << RESET_COLOR;
	//std::cout << "Drawn to " << m_playerPos.y + 1 << " " << m_playerPos.x * 4 + 2;
}
