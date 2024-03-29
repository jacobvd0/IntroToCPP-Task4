#include "Spell.h"
#include <iostream>
#include "GameDefines.h"
#include "Tools.h"

Spell::Spell()
{

}

Spell::~Spell()
{
}

// Placeholder for spells, if a spell doesn't have a function this one will be called instead
void Spell::Cast(Room& room, Player& plr)
{
    Tools ctools;
    std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
    std::cout << CSI << "4M" << CSI << "4L" << std::endl;

    std::cout << "It doesn't seem to do much.\n";
    ctools.Pause();
}

// Returns the spell name
String Spell::GetName()
{
    return m_spellName;
}

// Sets the spell name
void Spell::SetName(String str)
{
    m_spellName = str;
}
