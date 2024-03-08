#include "Heal.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"
#include "Tools.h"

Heal::Heal()
{
	SetName(m_spellName);
}

Heal::~Heal()
{
}

// Casts the heal spell
void Heal::Cast(Room& room, Player& plr)
{
	Tools ctools;
	int roomType = room.getType();

	// Makes sure the player has enough Mana
	if (plr.getMana() >= m_cost) {
		plr.takeMana(m_cost);
		plr.addHealth(15);

		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		std::cout << "You cast Heal... \nYou gained 15 HP!\n";
		if (roomType == ENEMY)
			std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;


		ctools.Pause();
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;


		// Checks if the player is in an enemy room
		if (roomType == ENEMY) {
			if (room.getEnemyHP() != 0) {
				room.attackPlayer(plr);
			}
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
