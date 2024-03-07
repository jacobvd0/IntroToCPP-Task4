#pragma once
#include "Spell.h"
class Freeze : public Spell
{
public:
	Freeze();
	~Freeze();

	void Cast(Room& room, Player& plr) override;

private:
	String m_spellName = "Freeze";
	int m_cost = 20;
};

