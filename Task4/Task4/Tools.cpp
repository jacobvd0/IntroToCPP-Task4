#include "Tools.h"
#include <iostream>
#include "GameDefines.h"

void Tools::Pause()
{
	std::cout << "Press Enter to continue\n";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << HIDE_INPUT;
	std::cin.get();
	std::cout << RESET_COLOR;
}
