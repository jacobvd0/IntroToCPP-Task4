#include <iostream>
#include "Game.h"
#include "GameDefines.h"

int main()
{
    Game game;

    // tries to enable virtual terminal, if it doesn't work exit the game
    if (!game.enableVirtualTerminal()) {
        std::cout << "The virtual terminal processing mode could not be activated.\n";
        std::cout << "Press enter to exit.\n";
        std::cin.get();
        return 0;
    }

    std::cout << CSI << "4M" << CSI << "4L" << std::endl;
    game.initializeMap();

    while (!game.isGameOver()) {
        game.update();
    }

}
