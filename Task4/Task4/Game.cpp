#include "Game.h"
#include <Windows.h>
#include <iostream>
#include "GameDefines.h"
#include "Point2D.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::isGameOver()
{
    return m_gameOver;
}

bool Game::enableVirtualTerminal()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return false;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        return false;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
        return false;

    return true;
}

void Game::initializeMap()
{
    srand(time(NULL));
    for (int h = 0; h < STARTER_MAP_HEIGHT; h++) {
        for (int w = 0; w < STARTER_MAP_WIDTH; w++) {
            m_map[h][w].setPosition(Point2D{w, h});

            int type = rand() % (MAX_RANDOM_TYPE * 2);
            if (type < MAX_RANDOM_TYPE) {
                m_map[h][w].setType(type);
            }
            else {
                m_map[h][w].setType(EMPTY);
            }
            

            m_map[h][w].draw();
        }
    }

    m_map[0][0].setType(ENTER);
    m_map[0][0].draw();
    m_map[STARTER_MAP_HEIGHT-1][STARTER_MAP_WIDTH-1].setType(EXIT);
    m_map[STARTER_MAP_HEIGHT-1][STARTER_MAP_WIDTH-1].draw();
}

void Game::drawMap()
{
}
