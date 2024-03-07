#include "WoodenSword.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"

WoodenSword::WoodenSword()
{
	SetDescription(m_itemDescription);
	SetName(m_itemName);
}

WoodenSword::~WoodenSword()
{
}

void WoodenSword::Use(Room& room, Player& plr)
{
	int roomType = room.getType();

	if (roomType == ENEMY) {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		srand(time(NULL));
		int dmg = (rand() % m_dmgMax) + m_dmgMin;

		room.dealDamage(dmg);
		std::cout << "You used your wooden sword... \nIt delt " << dmg << " damage!\n";
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
