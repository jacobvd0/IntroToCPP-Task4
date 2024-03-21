#pragma once
#include "Point2D.h"
//#include "OldSword.h"
#include "Room.h"
#include "String.h"
#include <vector>

class Player
{
public:
	Player();
	Player(Point2D pos);
	Player(int x, int y);
	~Player();

	Point2D GetPosition();
	void SetPosition(Point2D pos);
	void draw();
	void attack(Room& room, Player& plr);
	void useItem(int item, Room& room, Player& plr);
	void inspectItem(int item);
	bool pickup(int item);
	void removeItem(int item);

	int getHealth();
	int getMaxHealth();
	void addHealth(int health);
	void dealDamage(int dmg);

	int getMana();
	void takeMana(int mana);
	void addMana(int mana);

	void castSpell(String& spell, Room& room, Player& plr);

	int getEnemyKills();
	void addEnemyKill();
	void addScore(int score);
	int getScore();
	void resetScore();

	void listItems();
	void listSpells();
private:
	Point2D m_playerPos;
	int m_inventory[5];
	int m_health = 100;
	int m_maxhealth = 100;
	//String m_spellbook[3] = {"fireball", "freeze", "heal"};
	std::vector<String> m_newSpellBook;
	int m_mana = 100;
	int m_maxMana = 200;

	void executeSpell(String& spell, Room& room, Player& plr);

	int m_score = 0;
	int m_enemyKills;

	//OldSword m_oldsword; // this is the only item stored here since it has a durability
};

