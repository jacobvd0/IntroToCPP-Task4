#include "Player.h"
#include "GameDefines.h"
#include <iostream>
#include "OldSword.h"

Player::Player()
{
	m_playerPos = Point2D{0,0};
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = EMPTY;
	}
}

Player::Player(Point2D pos)
{
	m_playerPos = pos;
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = EMPTY;
	}
}

Player::Player(int x, int y)
{
	m_playerPos = Point2D{ x, y };
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = EMPTY;
	}
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

void Player::useItem(int item, Room& room, Player& plr)
{
	for (int i = 0; i < 5; i++) {
		if (m_inventory[i] == item) {
			// confirmed that the player has the item in their inv
			// run the use function here

			switch (item) {
			case OLD_SWORD:
				OldSword m_oldsword;
				m_oldsword.Use(room, plr);
				break;
			}
		}
	}
}

bool Player::pickup(int item)
{
	for (int i = 0; i < 5; i++) {
		if (m_inventory[i] == EMPTY) {
			m_inventory[i] = item;
			return true;
		}
	}
	return false;
}

int Player::getHealth()
{
	return m_health;
}

int Player::getMaxHealth()
{
	return m_maxhealth;
}

void Player::dealDamage(int dmg)
{
	m_health -= dmg;
	if (m_health < 0)
		m_health = 0;
}
