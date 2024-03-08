#include "Room.h"
#include "GameDefines.h"
#include <iostream>
#include "Player.h"
#include "Tools.h"

Room::Room()
{
	m_location = { 0,0 };
	m_item = AIR;
	m_type = EMPTY;
}

Room::~Room()
{
}

// Sets the room's type
void Room::setType(int type)
{
	m_type = type;
}

// Gets the room's type
int Room::getType()
{
	return m_type;
}

// Sets the item in the room (usually used if a player drops an item in the room)
void Room::setItem(int item)
{
	m_item = item;
}

// Gets the dropped item in the room
int Room::getItem()
{
	return m_item;
}

// Draws the room on the map
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

// Draws the room's description under the map
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

// Sets the room's position
void Room::setPosition(Point2D pos)
{
	m_location = pos;
}

void Room::executeCommand()
{
}

void Room::dealDamage(int dmg)
{
	m_enemyHP -= dmg;
	if (m_enemyHP < 0)
		m_enemyHP = 0;

	if (m_enemyHP == 0)
		m_type = EMPTY;
}

void Room::attackPlayer(Player& plr)
{
	Tools ctools;
	std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;
	srand(time(NULL));
	int dmg = (rand() % 6) + 1;
	plr.dealDamage(dmg);

	std::cout << "You were attacked! \nYou took " << dmg << " damage!\n";
	std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";
	std::cout << "Enemy HP: " << getEnemyHP() << "/" << getEnemyMaxHP() << std::endl;
	//m_usesLeft--;

	ctools.Pause();
	std::cout << CSI << MAX_MAP_HEIGHT + 7 << ";" << 1 << "H";
	std::cout << CSI << "7M" << CSI << "7L" << std::endl;
}

int Room::getEnemyHP()
{
	return m_enemyHP;
}

int Room::getEnemyMaxHP()
{
	return m_maxHP;
}

void Room::pickup(Player& plr)
{
	Tools ctools;
	int minItem = OLD_SWORD;
	int maxItem = WOOD_SWORD;

	if (m_type == ITEM) {
		srand(time(NULL));
		minItem--;
		int item = rand() % (maxItem - minItem + 1) + minItem;

		if (item > minItem) {
			if (plr.pickup(item)) {
				m_type = EMPTY;
				String itemName;
				switch (item) {
				case OLD_SWORD:
					itemName = "Old Sword";
					break;
				case WOOD_SWORD:
					itemName = "Wooden Sword";
					break;
				}


				std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
				std::cout << CSI << "4M" << CSI << "4L" << std::endl;

				std::cout << "You picked up a " << itemName.CStr() << "!" << std::endl;

				ctools.Pause();
				std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
				std::cout << CSI << "5M" << CSI << "5L" << std::endl;
			}
			else {
				std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
				std::cout << CSI << "4M" << CSI << "4L" << std::endl;

				std::cout << "You don't have enough inventory space!" << std::endl;

				ctools.Pause();
				std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
				std::cout << CSI << "5M" << CSI << "5L" << std::endl;

			}

			
		}
		else {
			m_type = EMPTY;
			int mana = (rand() % 10) + 5;
			plr.addMana(mana);
			std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
			std::cout << CSI << "4M" << CSI << "4L" << std::endl;

			std::cout << "You gained " << mana << " mana! \nYou now have " << plr.getMana() << " mana." << std::endl;

			ctools.Pause();
			std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
			std::cout << CSI << "5M" << CSI << "5L" << std::endl;
		}
		
		
	}
}
