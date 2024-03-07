#include "Freeze.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"

Freeze::Freeze()
{
	SetName(m_spellName);
}

Freeze::~Freeze()
{
}

void Freeze::Cast(Room& room, Player& plr)
{
	int roomType = room.getType();

	if (plr.getMana() >= m_cost) {
		if (roomType == ENEMY) {
			plr.takeMana(m_cost);
			// makes a random number between 1 and 10
			// if the number is 5 the enemy will be frozen and won't attack for that turn
			srand(time(NULL));
			int randomNum = (rand() % 3) + 1;


			std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
			std::cout << CSI << "4M" << CSI << "4L" << std::endl;
			
			int dmg = 5;

			room.dealDamage(dmg);
			std::cout << "You cast Freeze... \nIt delt " << dmg << " damage!\n";
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
				if (randomNum == 2) {
					std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
					std::cout << CSI << "4M" << CSI << "4L" << std::endl;

					std::cout << "The enemy is frozen! \nIt couldn't attack.\n";
					std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";
					std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;

					std::cout << "Press Enter to continue\n";
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					std::cout << HIDE_INPUT;
					std::cin.get();
					std::cout << RESET_COLOR;
					std::cout << CSI << MAX_MAP_HEIGHT + 7 << ";" << 1 << "H";
					std::cout << CSI << "7M" << CSI << "7L" << std::endl;
				}
				else {
					room.attackPlayer(plr);
				}
				
			}
			else {
				room.setType(EMPTY);
				std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
				std::cout << CSI << "4M" << CSI << "4L" << std::endl;
				std::cout << "The enemy died!\n";
				std::cout << "HP: " << plr.getHealth() << "/" << plr.getMaxHealth() << "\n";
				plr.addMana(15);

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