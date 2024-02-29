#pragma once
#include "Item.h"
class OldSword : public Item
{
public:
	OldSword();
	~OldSword();

	void Use() override;
	
private:
	String m_itemName = "Old Sword";
	String m_itemDescription = "An old sword, looks like it's almost broken. \nDeals 2-5 damage when used.";
	int m_usesLeft = 2;
	int m_dmgMin = 2;
	int m_dmgMax = 5;
};

