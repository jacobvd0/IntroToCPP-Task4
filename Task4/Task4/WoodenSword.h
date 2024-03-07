#pragma once
#include "Item.h"
#include "Room.h"
#include "Player.h"
class WoodenSword : public Item
{
public:
	WoodenSword();
	~WoodenSword();

	void Use(Room& room, Player& plr) override;

private:
	String m_itemName = "Wooden Sword";
	String m_itemDescription = "A wooden sword! \nDeals 4-8 damage when used.";
	//int m_usesLeft = 2;
	int m_dmgMin = 4;
	int m_dmgMax = 8;
};

