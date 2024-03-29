#include "Fireball.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"
#include "Tools.h"


Fireball::Fireball()
{
	SetName(m_spellName);
}

Fireball::~Fireball()
{
}

// Casts the Fireball spell
void Fireball::Cast(Room& room, Player& plr)
{
	Tools ctools;
	int roomType = room.getType();

	// Checks if the player has enough Mana
	if (plr.getMana() >= m_cost) {
		// Checks if the player is in an enemy room
		if (roomType == ENEMY) {
			plr.takeMana(m_cost);
			std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
			std::cout << CSI << "4M" << CSI << "4L" << std::endl;
			srand(time(NULL));
			int dmg = 10;

			room.dealDamage(dmg);
			std::cout << "You cast Fireball... \nIt dealt " << dmg << " damage!\n";
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
	else {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;

		std::cout << "You don't have enough mana...\n";

		ctools.Pause();
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;
	}
}
