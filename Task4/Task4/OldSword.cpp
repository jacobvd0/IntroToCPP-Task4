#include "OldSword.h"
#include <iostream>
#include "GameDefines.h"
#include "Player.h"
#include "Tools.h"

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
	Tools ctools;
	int roomType = room.getType();
	
	if (roomType == ENEMY) {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		srand(time(NULL));
		int dmg = (rand() % 5) + 2;

		room.dealDamage(dmg);
		std::cout << "You used your old sword... \nIt delt " << dmg << " damage!\n";
		std::cout << "Enemy HP: " << room.getEnemyHP() << "/" << room.getEnemyMaxHP() << std::endl;


		ctools.Pause();
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
			plr.addMana(15);

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
