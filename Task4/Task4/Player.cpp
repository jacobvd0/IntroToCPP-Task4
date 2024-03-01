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

// Gets the current position of the player
Point2D Player::GetPosition()
{
	return m_playerPos; 
}

// Sets the player's position
void Player::SetPosition(Point2D pos)
{
	m_playerPos = pos;
}

// Draws the player on the map
void Player::draw()
{
	std::cout << CSI << m_playerPos.y + 1 << ";" << m_playerPos.x * 4 + 2 << "H";

	std::cout << GREY << "[" << GREEN << PLAYER_ICON << GREY << "] " << RESET_COLOR;
	//std::cout << "Drawn to " << m_playerPos.y + 1 << " " << m_playerPos.x * 4 + 2;
}

void Player::useItem(int item)
{
	for (int i = 0; i < 5; i++) {
		if (i == item) {
			// confirmed that the player has the item in their inv
			// run the use function here
		}
	}
}
