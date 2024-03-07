#include "Player.h"
#include "GameDefines.h"
#include <iostream>
#include "OldSword.h"
#include "WoodenSword.h"
#include "Fireball.h"
#include "Heal.h"
#include "Freeze.h"

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
			OldSword oldSword;
			WoodenSword woodSword;
			// confirmed that the player has the item in their inv
			// run the use function here

			switch (item) {
			case OLD_SWORD:
				oldSword.Use(room, plr);
				break;
			case WOOD_SWORD:
				woodSword.Use(room, plr);
				break;
			}
		}
	}
}

void Player::inspectItem(int item)
{
	for (int i = 0; i < 5; i++) {
		if (m_inventory[i] == item) {
			OldSword oldSword;
			WoodenSword woodSword;
			// confirmed that the player has the item in their inv
			// run the use function here

			switch (item) {
			case OLD_SWORD:
				oldSword.Inspect();
				break;
			case WOOD_SWORD:
				woodSword.Inspect();
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

void Player::addHealth(int health)
{
	m_health += health;
	if (m_health > m_maxhealth) {
		m_health = m_maxhealth;
	}
}

void Player::dealDamage(int dmg)
{
	m_health -= dmg;
	if (m_health < 0)
		m_health = 0;
}

int Player::getMana()
{
	return m_mana;
}

void Player::takeMana(int mana)
{
	m_mana -= mana;
	if (m_mana < 0) {
		m_mana = 0;
	}
}

void Player::addMana(int mana)
{
	m_mana += mana;
	if (m_mana > m_maxMana) {
		m_mana = m_maxMana;
	}
}

void Player::castSpell(String& spell, Room& room, Player& plr)
{
	int spellbookLength = 3;

	spellbookLength--;

	if (m_spellbook[spellbookLength / 2] > spell) {
		// search up
		for (int i = spellbookLength / 2; i <= spellbookLength; i++) {
			if (m_spellbook[i].EqualTo(spell)) {
				executeSpell(spell, room, plr);
			}
		}
	}
	else if (m_spellbook[spellbookLength / 2].EqualTo(spell)) {
		executeSpell(spell, room, plr);
	}
	else {
		// search down
		for (int i = spellbookLength / 2; i >= 0; i--) {
			if (m_spellbook[i].EqualTo(spell)) {
				executeSpell(spell, room, plr);
			}
		}
	}
}

void Player::executeSpell(String& spell, Room& room, Player& plr)
{
	if (spell.EqualTo("fireball")) {
		Fireball spell;
		spell.Cast(room, plr);
	}
	else if (spell.EqualTo("heal")) {
		Heal spell;
		spell.Cast(room, plr);
	}
	else if (spell.EqualTo("freeze")) {
		Freeze spell;
		spell.Cast(room, plr);
	}

}
