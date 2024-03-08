#pragma once
#include "Room.h"
#include "GameDefines.h"
#include "Player.h"
#include "OldSword.h"

class Game
{
public:
	Game();
	~Game();

	bool isGameOver();
	bool enableVirtualTerminal();
	void initializeMap();
	void drawInfo();

	void update();

	int getPlayerScore();
	int getLevelScore();
	int getEnemyKills();

private:
	OldSword testSword; // temporary item until inventory is added

	void newLevel();
	void getCommand();
	int m_currentFloor = 0;
	Room m_map[STARTER_MAP_HEIGHT][STARTER_MAP_WIDTH];
	bool m_gameOver = false;
	Player m_player;

	int m_completedLevels;
};