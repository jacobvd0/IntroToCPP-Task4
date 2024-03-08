#include "WoodenSword.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"
#include "Tools.h"

WoodenSword::WoodenSword()
{
	SetDescription(m_itemDescription);
	SetName(m_itemName);
}

WoodenSword::~WoodenSword()
{
}

// Uses the Wooden Sword
void WoodenSword::Use(Room& room, Player& plr)
{
	Tools ctools;
	int roomType = room.getType();

	// Makes sure the player is in an enemy room
	if (roomType == ENEMY) {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		srand(time(NULL));
		int dmg = (rand() % m_dmgMax) + m_dmgMin;

		room.dealDamage(dmg);
		std::cout << "You used your wooden sword... \nIt dealt " << dmg << " damage!\n";
		std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;


		ctools.Pause();
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;

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
			std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";
			plr.addScore(10);
			plr.addMana(15);
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
