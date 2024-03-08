#include <iostream>
#include "Game.h"
#include "GameDefines.h"
#include "Tools.h"

int main()
{
    Game game;
    Tools ctools;

    // tries to enable virtual terminal, if it doesn't work exit the game
    if (!game.enableVirtualTerminal()) {
        std::cout << "The virtual terminal processing mode could not be activated.\n";
        std::cout << "Press enter to exit.\n";
        std::cin.get();
        return 0;
    }

    game.initializeMap();

    while (!game.isGameOver()) {
        game.update();
    }

    std::cout << CSI << MAX_MAP_HEIGHT + 4 << ";" << 1 << "H";
    std::cout << CSI << "4M" << CSI << "4L" << std::endl;

    std::cout << RED << "You died...\n" << RESET_COLOR;
    std::cout << WHITE << "You killed " << game.getEnemyKills() << " enemies (+" << game.getEnemyKills() * 10 << ")" << std::endl;
    std::cout << WHITE << "You completed " << game.getLevelScore() << " levels (+" << game.getLevelScore() * 7 << ")\n";

   std::cout << WHITE << "Your total score is " << game.getPlayerScore() << "." << std::endl;


    ctools.Pause();

}
