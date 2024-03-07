#include "Heal.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"

Heal::Heal()
{
	SetName(m_spellName);
}

Heal::~Heal()
{
}

void Heal::Cast(Room& room, Player& plr)
{
	int roomType = room.getType();

	if (plr.getMana() >= m_cost) {
		plr.takeMana(m_cost);
		plr.addHealth(15);

		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		std::cout << "You cast Heal... \nYou gained 15 HP!\n";
		std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";
		if (roomType == ENEMY)
			std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;


		std::cout << "Press Enter to continue\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << HIDE_INPUT;
		std::cin.get();
		std::cout << RESET_COLOR;
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;



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

		std::cout << "Press Enter to continue\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << HIDE_INPUT;
		std::cin.get();
		std::cout << RESET_COLOR;
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;
	}
}
