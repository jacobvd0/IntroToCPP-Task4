#pragma once
#include "Spell.h"
class Heal : public Spell
{
public:
	Heal();
	~Heal();

	void Cast(Room& room, Player& plr) override;

private:
	String m_spellName = "Heal";
	int m_cost = 20;
};

