#include "Game.h"
#include <Windows.h>
#include <iostream>
#include "GameDefines.h"
#include "Point2D.h"
#include "OldSword.h"
#include <windows.h>
#include <shellapi.h>

Game::Game()
{
}

Game::~Game()
{
}

// Checks if the game has ended (player died)
bool Game::isGameOver()
{
    return m_gameOver;
}

// Enables the virtual terminal
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

// Initializes the starter map with random rooms
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
    m_player.draw();
    m_map[STARTER_MAP_HEIGHT-1][STARTER_MAP_WIDTH-1].setType(EXIT);
    m_map[STARTER_MAP_HEIGHT-1][STARTER_MAP_WIDTH-1].draw();
    m_map[0][0].drawDescription();
}

void Game::drawMap()
{
}

// Game update loop
void Game::update()
{
    Point2D playerPos = m_player.GetPosition();

    m_map[playerPos.y][playerPos.x].drawDescription();

    getCommand();
    
}

// Gets input from the player
void Game::getCommand()
{
    Point2D playerPos = m_player.GetPosition();

    std::cout << "What do you want to do?\n";
    std::cout << YELLOW;
    String input = input.ReadFromConsole();
    std::cout << RESET_COLOR;
    if (input == "move down") {
        if (playerPos.y != STARTER_MAP_HEIGHT - 1)
            m_player.SetPosition(Point2D{ playerPos.x, playerPos.y + 1 });
    }
    else if (input == "move up") {
        if (playerPos.y != 0)
            m_player.SetPosition(Point2D{ playerPos.x, playerPos.y - 1 });
    }
    else if (input == "move left") {
        if (playerPos.x != 0)
            m_player.SetPosition(Point2D{ playerPos.x - 1, playerPos.y });
    }
    else if (input == "move right") {
        if (playerPos.x != STARTER_MAP_WIDTH - 1)
            m_player.SetPosition(Point2D{ playerPos.x + 1, playerPos.y });
    }
    else if (input == "use old sword") {
        testSword.Use();
    }
    else if (input == "inspect old sword") {
        testSword.Inspect();
    }
    else if (input == "/minecraft") {
        // Riley's fault this exists
        ShellExecute(0, 0, L"https://minecraft.net/download", 0, 0, SW_SHOW);
    }
    m_map[playerPos.y][playerPos.x].draw();
    m_player.draw();
}
