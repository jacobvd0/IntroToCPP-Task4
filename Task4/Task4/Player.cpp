#include "Player.h"
#include "GameDefines.h"
#include <iostream>
#include "OldSword.h"
#include "WoodenSword.h"
#include "Fireball.h"
#include "Heal.h"
#include "Freeze.h"
#include "Tools.h"
#include "HealthPotion.h"
#include <algorithm>

Player::Player()
{
	m_playerPos = Point2D{0,0};
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = EMPTY;
	}
	m_enemyKills = 0;
	m_newSpellBook.push_back("fireball");
	m_newSpellBook.push_back("heal");
	m_newSpellBook.push_back("freeze");
}

Player::Player(Point2D pos)
{
	m_playerPos = pos;
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = EMPTY;
	}
	m_enemyKills = 0;
	m_newSpellBook.push_back("fireball");
	m_newSpellBook.push_back("heal");
	m_newSpellBook.push_back("freeze");
}

Player::Player(int x, int y)
{
	m_playerPos = Point2D{ x, y };
	for (int i = 0; i < 5; i++) {
		m_inventory[i] = EMPTY;
	}
	m_enemyKills = 0;
	m_newSpellBook.push_back("fireball");
	m_newSpellBook.push_back("heal");
	m_newSpellBook.push_back("freeze");
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
}

// Standalone attack (uses no items)
void Player::attack(Room& room, Player& plr)
{
	Tools ctools;

	if (room.getType() == ENEMY) {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;

		room.dealDamage(2);

		std::cout << "You punched the enemy... \nIt only did 2 damage!\n";
		std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;

		ctools.Pause();
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;

		// Checks if the enemy is dead, if it isn't it'll attack the player
		if (room.getEnemyHP() != 0) {
			room.attackPlayer(plr);
		}
		else {
			room.setType(EMPTY);
			std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
			std::cout << CSI << "4M" << CSI << "4L" << std::endl;
			std::cout << "The enemy died!\n";
			plr.addMana(15);
			plr.addScore(10);
			plr.addEnemyKill();

			ctools.Pause();
			std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
			std::cout << CSI << "5M" << CSI << "5L" << std::endl;
		}
	}
	else {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;

		std::cout << "There's nothing to attack...\n";

		ctools.Pause();
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;
	}
}

// Uses the provided item if the player owns it
void Player::useItem(int item, Room& room, Player& plr)
{
	for (int i = 0; i < 5; i++) {

		// confirms that the player has the item in their inv
		if (m_inventory[i] == item) {
			OldSword oldSword;
			WoodenSword woodSword;
			HealthPotion healthPotion;

			switch (item) {
			case OLD_SWORD:
				oldSword.Use(room, plr);
				break;
			case WOOD_SWORD:
				woodSword.Use(room, plr);
				break;
			case HEALTH_POTION:
				healthPotion.Use(room, plr);
				break;
			}
		}
	}
}

// Shows information about the item
void Player::inspectItem(int item)
{
	for (int i = 0; i < 5; i++) {

		// confirms that the player has the item in their inv
		if (m_inventory[i] == item) {
			OldSword oldSword;
			WoodenSword woodSword;
			HealthPotion healthPotion;

			switch (item) {
			case OLD_SWORD:
				oldSword.Inspect();
				break;
			case WOOD_SWORD:
				woodSword.Inspect();
				break;
			case HEALTH_POTION:
				healthPotion.Inspect();
				break;

			}

		}
	}
}

// Picks up a random item
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

// Removes an item from the player's inventory
void Player::removeItem(int item)
{
	for (int i = 0; i < 5; i++) {
		if (m_inventory[i] == item) {
			m_inventory[i] = AIR;
		}
	}
}

// Returns the player's health
int Player::getHealth()
{
	return m_health;
}

// Returns the player's max health
int Player::getMaxHealth()
{
	return m_maxhealth;
}

// Adds health to the player
void Player::addHealth(int health)
{
	m_health += health;
	if (m_health > m_maxhealth) {
		m_health = m_maxhealth;
	}
}

// Deals damage to the player
void Player::dealDamage(int dmg)
{
	m_health -= dmg;
	if (m_health < 0)
		m_health = 0;
}

// Returns the player's current mana
int Player::getMana()
{
	return m_mana;
}

// Removed mana from the player
void Player::takeMana(int mana)
{
	m_mana -= mana;
	if (m_mana < 0) {
		m_mana = 0;
	}
}

// Gives mana to the player
void Player::addMana(int mana)
{
	m_mana += mana;
	if (m_mana > m_maxMana) {
		m_mana = m_maxMana;
	}
}

// Casts a spell from the spellbook
void Player::castSpell(String& spell, Room& room, Player& plr)
{
	// Length of the spellbook
	int spellbookLength = 3;

	


	// Remove 1 due to arrays starting at 0
	//spellbookLength--;

	//// Binary search to check if the player owns that spell
	//if (m_spellbook[spellbookLength / 2] > spell) {
	//	// search up
	//	for (int i = spellbookLength / 2; i <= spellbookLength; i++) {
	//		if (m_spellbook[i].EqualTo(spell)) {
	//			executeSpell(spell, room, plr);
	//		}
	//	}
	//}
	//else if (m_spellbook[spellbookLength / 2].EqualTo(spell)) {
	//	executeSpell(spell, room, plr);
	//}
	//else {
	//	// search down
	//	for (int i = spellbookLength / 2; i >= 0; i--) {
	//		if (m_spellbook[i].EqualTo(spell)) {
	//			executeSpell(spell, room, plr);
	//		}
	//	}
	//} 

	//std::sort(m_spellbook[0], m_spellbook[spellbookLength - 1]);
	std::sort(m_newSpellBook.begin(), m_newSpellBook.end());

	int l = 0;
	int r = spellbookLength-1;

	while (true) {
		int middle = (l + r) / 2;
		if (m_newSpellBook[middle].EqualTo(spell)) {
			executeSpell(spell, room, plr);
			break;
		}
		else if (m_newSpellBook[middle] < spell) {
			l = middle + 1;
		}
		/*else if (m_newSpellBook[middle] < spell) {
			r = middle - 1;
		}*/
		else {
			//std::cout << "No conditions met\nMiddle: " << middle << "\nL: " << l << "\nR: " << r << std::endl;
			//l++;
			r = middle - 1;
		}
	}

}

// Returns the number of enemies the player has killed
int Player::getEnemyKills()
{
	return m_enemyKills;
}

// Adds a kill to the enemy kill counter
void Player::addEnemyKill()
{
	m_enemyKills++;
}

// Adds score to the player
void Player::addScore(int score)
{
	m_score += score;
}

// Returns the player's score
int Player::getScore()
{
	return m_score;
}

// Resets the score to 0
void Player::resetScore()
{
	m_score = 0;
}

// List all the items in the player's inventory
void Player::listItems()
{
	Tools ctools;

	std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;
	std::cout << CYAN << "Inventory:\n";

	// Loops through all items in the m_items array and prints them if the item isn't empty (AIR)
	for (int i = 0; i < 5; i++) {
		switch (m_inventory[i]) {
		case OLD_SWORD:
			std::cout << WHITE << "Old Sword" << RESET_COLOR << std::endl;
			break;
		case WOOD_SWORD:
			std::cout << WHITE << "Wooden Sword" << RESET_COLOR << std::endl;
			break;
		}
	}
	ctools.Pause();
	std::cout << CSI << MAX_MAP_HEIGHT + 8 << ";" << 1 << "H";
	std::cout << CSI << "8M" << CSI << "8L" << std::endl;
}

// Executes a spell
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

// Lists all the spells in the player's spellbook
void Player::listSpells()
{
	Tools ctools;

	std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;
	std::cout << CYAN << "Your Spellbook:\n";

	for (int i = 0; i < 3; i++) {
		std::cout << WHITE << m_newSpellBook[i].CStr() << RESET_COLOR << std::endl;
	}
	ctools.Pause();
	std::cout << CSI << MAX_MAP_HEIGHT + 8 << ";" << 1 << "H";
	std::cout << CSI << "8M" << CSI << "8L" << std::endl;
}
