#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
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
    for (int h = 0; h < STARTER_MAP_HEIGHT; h++) {
        for (int w = 0; w < STARTER_MAP_WIDTH; w++) {
            std::cout << "Room ";
        }
        std::cout << "\n";
    }
}

void Game::drawMap()
{
}
