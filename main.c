#include <stdio.h>
#include "game/gameBoard.h";
#include "game/utils.h"
#include "game/modes/HumanVsHuman.h"
#include "game/modes/HumanVsBot.h"

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
        case 2: // human against human
            printf("Starting Human against Computer Game!\n");
            gameBoard.gameMode = GAMEMODE_HumanVsComputer;
            startHumanVsBot(&gameBoard);
            break;
        default:
            printf("Please provide a valid option :(\n");
            main();
            break;
    }
    return 0;
}
