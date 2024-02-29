#pragma once
#include "Room.h"
#include "GameDefines.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	bool isGameOver();
	bool enableVirtualTerminal();
	void initializeMap();
	void drawMap();

	void update();

private:
	void getCommand();
	int m_currentFloor = 0;
	Room m_map[STARTER_MAP_HEIGHT][STARTER_MAP_WIDTH];
	bool m_gameOver = false;
	Player m_player;
};