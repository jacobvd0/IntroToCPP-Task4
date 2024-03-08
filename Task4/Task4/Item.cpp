#include "Item.h"
#include <iostream>
#include "GameDefines.h"
#include "Tools.h"

Item::Item()
{
    
}

Item::~Item()
{
}

// Placeholder use in case it isn't added to the item's class
void Item::Use(Room& room, Player& plr)
{
    Tools ctools;
    std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
    std::cout << CSI << "4M" << CSI << "4L" << std::endl;

    std::cout << "It doesn't seem to do much.\n";
    ctools.Pause();
}

// Shows information about the item using the item name and description variables
void Item::Inspect()
{
    Tools ctools;
    std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
    std::cout << CSI << "4M" << CSI << "4L" << std::endl;
    std::cout << LIGHT_GREY << "=============== " << YELLOW << "ITEM INFO" << LIGHT_GREY << " ===============" << RESET_COLOR << std::endl;
    std::cout << "Name: " << WHITE << m_itemName.CStr() << RESET_COLOR << std::endl;
    std::cout << "Description: " << WHITE << m_itemDescription.CStr() << RESET_COLOR << std::endl;
    std::cout << LIGHT_GREY << "=========================================" << RESET_COLOR << std::endl;

    ctools.Pause();
    std::cout << CSI << MAX_MAP_HEIGHT + 6 << ";" << 1 << "H";
    std::cout << CSI << "6M" << CSI << "6L" << std::endl;
}

// Returns the item description
String Item::GetDescription()
{
    return m_itemDescription;
}

// Sets the item description
void Item::SetDescription(String str)
{
    m_itemDescription = str;
}

// Returns the item name
String Item::GetName()
{
    return m_itemName;
}

// Sets the item name
void Item::SetName(String str)
{
    m_itemName = str;
}
