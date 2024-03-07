#pragma once
#include "Spell.h"
class Fireball : public Spell
{
public:
	Fireball();
	~Fireball();

	void Cast(Room& room, Player& plr) override;

private:
	String m_spellName = "Fireball";
	int m_cost = 10;
};

