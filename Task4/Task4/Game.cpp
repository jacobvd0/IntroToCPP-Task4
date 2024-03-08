#include "Game.h"
#include <Windows.h>
#include <iostream>
#include "GameDefines.h"
#include "Point2D.h"
#include "OldSword.h"
#include <windows.h>
#include <shellapi.h>
#include "Tools.h"

Game::Game()
{
    // Gives the player a old sword to start off with
    m_player.pickup(OLD_SWORD);
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

// Draws the player's HP and Mana
void Game::drawInfo()
{
    std::cout << CSI << MAX_MAP_HEIGHT + 1 << ";" << 1 << "H";
    std::cout << CSI << "3M" << CSI << "3L" << std::endl;

    std::cout << CYAN << "HP: " << WHITE << m_player.getHealth() << "/" << m_player.getMaxHealth() << RESET_COLOR << std::endl;
    std::cout << CYAN << "Mana: " << WHITE << m_player.getMana() << "/200" << RESET_COLOR << std::endl;
}

// Game update loop
void Game::update()
{
    if (m_player.getHealth() != 0) {
        drawInfo();
        Point2D playerPos = m_player.GetPosition();

        m_map[playerPos.y][playerPos.x].drawDescription();

        getCommand();
    }
    else {
        m_gameOver = true;
    }
    
}

// Returns the player's current score
int Game::getPlayerScore()
{
    return m_player.getScore();
}

// Gets the amount of levels completed
int Game::getLevelScore()
{
    return m_completedLevels;
}

// Gets the amount of enemies killed by the player
int Game::getEnemyKills()
{
    return m_player.getEnemyKills();
}

// Creates a new level
void Game::newLevel()
{
    m_completedLevels++;
    m_player.addScore(7);
    m_player.SetPosition(Point2D{0,0});
    initializeMap();

}

// Gets input from the player
void Game::getCommand()
{
    Tools ctools;
    Point2D playerPos = m_player.GetPosition();

    std::cout << "What do you want to do? Use" << YELLOW << " HELP " << RESET_COLOR << "to view all commands.\n";
    
    std::cout << YELLOW;
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    String input = input.ReadFromConsole().ToLower();
    std::cout << RESET_COLOR;
    
    // Checks if the player wants to move
    if (input.Find("move") == 0) {
        if (m_map[playerPos.y][playerPos.x].getType() == ENEMY) {

            std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
            std::cout << CSI << "4M" << CSI << "4L" << std::endl;
            std::cout << "You can't leave this room yet!\n";

            ctools.Pause();
            std::cout << CSI << MAX_MAP_HEIGHT + 5 << ";" << 1 << "H";
            std::cout << CSI << "5M" << CSI << "5L" << std::endl;
            return;
        }

        // Down/South
        if (input.Find("down") != -1 || input.Find("south") != -1) {
            if (playerPos.y != STARTER_MAP_HEIGHT - 1)
                m_player.SetPosition(Point2D{ playerPos.x, playerPos.y + 1 });
        }
        // Up/North
        else if (input.Find("up") != -1 || input.Find("north") != -1) {
            if (playerPos.y != 0)
                m_player.SetPosition(Point2D{ playerPos.x, playerPos.y - 1 });
        }
        // Left/West
        else if (input.Find("left") != -1 || input.Find("west") != -1) {
            if (playerPos.x != 0)
                m_player.SetPosition(Point2D{ playerPos.x - 1, playerPos.y });
        }
        // Right/East
        else if (input.Find("right") != -1 || input.Find("east") != -1) {
            if (playerPos.x != STARTER_MAP_WIDTH - 1)
                m_player.SetPosition(Point2D{ playerPos.x + 1, playerPos.y });
        }
    }

    // WASD inputs
    else if (input == "w") {
        if (playerPos.y != 0)
            m_player.SetPosition(Point2D{ playerPos.x, playerPos.y - 1 });
    }
    else if (input == "a") {
        if (playerPos.x != 0)
            m_player.SetPosition(Point2D{ playerPos.x - 1, playerPos.y });
    }
    else if (input == "s") {
        if (playerPos.y != STARTER_MAP_HEIGHT - 1)
            m_player.SetPosition(Point2D{ playerPos.x, playerPos.y + 1 });
    }
    else if (input == "d") {
        if (playerPos.x != STARTER_MAP_WIDTH - 1)
            m_player.SetPosition(Point2D{ playerPos.x + 1, playerPos.y });
    }

    // Checks if the player wants to use an item
    else if (input.Find("use") == 0) {
        Point2D playerPos = m_player.GetPosition();

        if (input.Find("old sword") != -1) {
            m_player.useItem(OLD_SWORD, m_map[playerPos.y][playerPos.x], m_player);
        }
        else if (input.Find("wooden sword") != -1) {
            m_player.useItem(WOOD_SWORD, m_map[playerPos.y][playerPos.x], m_player);
        }
        else if (input.Find("health potion") != -1) {
            m_player.useItem(HEALTH_POTION, m_map[playerPos.y][playerPos.x], m_player);
        }
    }

    // Standalone attack (deals 2 damage)
    else if (input.Find("attack") == 0) {
        m_player.attack(m_map[playerPos.y][playerPos.x], m_player);
    }

    // Checks if the player wants to inspect an item
    else if (input.Find("inspect") == 0) {
        if (input.Find("old sword") != -1) {
            m_player.inspectItem(OLD_SWORD);
        }
        else if (input.Find("wooden sword") != -1) {
            m_player.inspectItem(WOOD_SWORD);
        }
        else if (input.Find("health potion") != -1) {
            m_player.inspectItem(HEALTH_POTION);
        }
    }

    // Spell casting
    else if (input.Find("cast") == 0) {
        if (input.Find("fireball") != -1) {
            String spell = "fireball";
            m_player.castSpell(spell, m_map[playerPos.y][playerPos.x], m_player);
        }
        else if (input.Find("heal") != -1) {
            String spell = "heal";
            m_player.castSpell(spell, m_map[playerPos.y][playerPos.x], m_player);
        }
        else if (input.Find("freeze") != -1) {
            String spell = "freeze";
            m_player.castSpell(spell, m_map[playerPos.y][playerPos.x], m_player);
        }

    }

    // Picks up the item in the current room
    else if (input == "pickup") {
        m_map[playerPos.y][playerPos.x].pickup(m_player);
    }

    // Enters the exit to go to the new level
    else if (input == "enter") {
        if (m_map[playerPos.y][playerPos.x].getType() == EXIT) {
            m_player.addScore(10);
            newLevel();
        }
        else if (m_map[playerPos.y][playerPos.x].getType() == ENTER) {
            std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
            std::cout << CSI << "4M" << CSI << "4L" << std::endl;
            std::cout << "The exit is blocked off...\n";

            ctools.Pause();
        }
        else {
            std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
            std::cout << CSI << "4M" << CSI << "4L" << std::endl;
            std::cout << "There's no exit here...\n";

            ctools.Pause();

        }
    }

    // Lists all the items in the player's inventory
    else if (input == "items") {
        m_player.listItems();
    }
    
    // Lists all the spells in the player's spellbook
    else if (input == "spells") {
        m_player.listSpells();
    }


    // Shows all the commands the user can do
    else if (input == "help") {
        std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
        std::cout << CSI << "4M" << CSI << "4L" << std::endl;
        std::cout << CYAN << "Commands:\n";
        std::cout << WHITE << "move (up/down/left/right) - Moves you in the direction you choose.\n";
        std::cout << "pickup - Picks up the item in the current room.\n";
        std::cout << "use (item name) - Uses an item, use this in fights with enemies. Use items to view your items.\n";
        std::cout << "inspect (item name) - Shows item info\n";
        std::cout << "cast (spell name) - Casts a spell. Use the spells command to view your spells.\n" << RESET_COLOR;

        ctools.Pause();
        std::cout << CSI << MAX_MAP_HEIGHT + 8 << ";" << 1 << "H";
        std::cout << CSI << "8M" << CSI << "8L" << std::endl;
    }

    // redraws the player and previous room in case the player was moved
    m_map[playerPos.y][playerPos.x].draw();
    m_player.draw();
}
