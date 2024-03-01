#include "OldSword.h"
#include <iostream>
#include "GameDefines.h"


OldSword::OldSword()
{
	SetDescription(m_itemDescription);
	SetName(m_itemName);

	m_usesLeft = 30;
}

OldSword::~OldSword()
{
}

void OldSword::Use()
{
	if (m_usesLeft > 0) {
		
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		std::cout << "Uses left " << m_usesLeft << "\n";
		m_usesLeft--;
		

		std::cout << "Press Enter to continue\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << HIDE_INPUT;
		std::cin.get();
		std::cout << RESET_COLOR;
	}
	else {
		std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
		std::cout << CSI << "4M" << CSI << "4L" << std::endl;
		std::cout << "The sword broke!\n";
		std::cout << "Use " << YELLOW << "DROP" << RESET_COLOR << " to drop the item.\n";

		std::cout << "Press Enter to continue\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << HIDE_INPUT;
		std::cin.get();
		std::cout << RESET_COLOR;
	}
	
}
