#include "OldSword.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"

OldSword::OldSword()
{
	SetDescription(m_itemDescription);
	SetName(m_itemName);

	//m_usesLeft = 30;
}

OldSword::~OldSword()
{
}

void OldSword::Use(Room& room, Player& plr)
{
	//if (m_usesLeft > 0) {
	//	
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		int dmg = 4;

		room.dealDamage(dmg);
		std::cout << "You used your old sword... \nIt delt " << dmg << " damage!\n";
		std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;
		//m_usesLeft--;
		

		std::cout << "Press Enter to continue\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << HIDE_INPUT;
		std::cin.get();
		std::cout << RESET_COLOR;
		std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
		std::cout << CSI << "5M" << CSI << "5L" << std::endl;

		room.attackPlayer();
	//}
	//else {
	//	std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
	//	std::cout << CSI << "4M" << CSI << "4L" << std::endl;
	//	std::cout << "The sword broke!\n";
	//	std::cout << "Use " << YELLOW << "DROP" << RESET_COLOR << " to drop the item.\n";

	//	std::cout << "Press Enter to continue\n";
	//	std::cin.clear();
	//	std::cin.ignore(std::cin.rdbuf()->in_avail());
	//	std::cout << HIDE_INPUT;
	//	std::cin.get();
	//	std::cout << RESET_COLOR;
	//}
	
}
