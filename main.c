#include <stdio.h>
#include "game/game.h";
#include "game/utils.h"
#include "game/modes/humanvshuman.h"

// main game structure and players ( Global Variables )
struct Game gameBoard;

int main() {
    int userOption = startGame();
    switch (userOption) {
        case 0:
            break;
        case 1: // human against human
            printf("Starting Human against Human Game!\n");
            gameBoard.gameMode = GAMEMODE_HumanVsHuman;
            startHumanVsHuman(&gameBoard);
            break;
        default:
            printf("Please provide a valid option :(\n");
            main();
            break;
    }
    return 0;
}
