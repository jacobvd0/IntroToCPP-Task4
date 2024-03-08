#pragma once
#include "Item.h"
#include "Room.h"
#include "Player.h"
class HealthPotion : public Item
{
public:
	HealthPotion();
	~HealthPotion();

	void Use(Room& room, Player& plr) override;

private:
	String m_itemName = "Health Potion";
	String m_itemDescription = "A small health potion.\nHeals 10 HP.";
};

