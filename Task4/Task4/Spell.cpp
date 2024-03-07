#include "Spell.h"
#include <iostream>
#include "GameDefines.h"

Spell::Spell()
{

}

Spell::~Spell()
{
}

void Spell::Cast(Room& room, Player& plr)
{
    std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
    std::cout << CSI << "4M" << CSI << "4L" << std::endl;

    std::cout << "It doesn't seem to do much.\n";
    std::cout << "Press Enter to continue\n";
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cout << HIDE_INPUT;
    std::cin.get();
    std::cout << RESET_COLOR;
}

String Spell::GetName()
{
    return m_spellName;
}

void Spell::SetName(String str)
{
    m_spellName = str;
}
