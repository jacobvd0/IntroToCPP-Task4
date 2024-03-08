#include "HealthPotion.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"
#include "Tools.h"

HealthPotion::HealthPotion()
{
	SetDescription(m_itemDescription);
	SetName(m_itemName);
}

HealthPotion::~HealthPotion()
{
}

// Uses the health potion
void HealthPotion::Use(Room& room, Player& plr)
{
	Tools ctools;
	int roomType = room.getType();
	std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;
	int heal = 10;

	// Removes the item after use
	plr.removeItem(HEALTH_POTION);


	plr.addHealth(heal);
	std::cout << "You used your health potion... \nYou gained " << heal << " HP!\n";
	if (room.getType() == ENEMY)
		std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;


	ctools.Pause();
	std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
	std::cout << CSI << "5M" << CSI << "5L" << std::endl;

	// Checks if the player is in an enemy room
	if (room.getType() == ENEMY) {
		// Makes sure the enemy is still alive
		// If it is, attack the player
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
		
}
