#pragma once
#include "String.h"
class Item
{
public:
	Item();
	~Item();

	virtual void Use();
	virtual void Inspect();

	String GetDescription();
	void SetDescription(String str);

	String GetName();
	void SetName(String str);
private:
	String m_itemDescription = "A mysterious item..."; // Placeholder desc, will be set per item.
	String m_itemName = "???"; // Placeholder name
};

