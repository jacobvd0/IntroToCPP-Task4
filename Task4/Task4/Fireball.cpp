#include "Fireball.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"

Fireball::Fireball()
{
	SetName(m_spellName);
}

Fireball::~Fireball()
{
}

void Fireball::Cast(Room& room, Player& plr)
{
	int roomType = room.getType();

	if (plr.getMana() >= m_cost) {
		if (roomType == ENEMY) {
			std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
			std::cout << CSI << "4M" << CSI << "4L" << std::endl;
			srand(time(NULL));
			int dmg = 10;

			room.dealDamage(dmg);
			std::cout << "You cast Fireball... \nIt delt " << dmg << " damage!\n";
			std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";
			std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;


			std::cout << "Press Enter to continue\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << HIDE_INPUT;
			std::cin.get();
			std::cout << RESET_COLOR;
			std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
			std::cout << CSI << "5M" << CSI << "5L" << std::endl;

			if (room.getEnemyHP() != 0) {
				room.attackPlayer(plr);
			}
			else {
				room.setType(EMPTY);
				std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
				std::cout << CSI << "4M" << CSI << "4L" << std::endl;
				std::cout << "The enemy died!\n";
				std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";

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
		else {
			std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
			std::cout << CSI << "4M" << CSI << "4L" << std::endl;

			std::cout << "There's nothing to attack...\n";

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
