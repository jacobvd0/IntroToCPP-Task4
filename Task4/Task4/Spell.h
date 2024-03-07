#pragma once
#include "String.h"
#include "Room.h"
#include "Player.h"
class Spell
{
public:
	Spell();
	~Spell();

	virtual void Cast(Room& room, Player& plr);
	String GetName();
	void SetName(String str);

private:
	String m_spellName = "???";
};

