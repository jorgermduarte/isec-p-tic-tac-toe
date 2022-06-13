//
// Created by Jorge Duarte on 4/22/2022.
// a2021110042
//

#include <stdio.h>
#include "game/gameBoard.h";
#include "game/modes/HumanVsHuman.h"
#include "game/modes/HumanVsBot.h"
#include <stdlib.h>

void initializeGame(struct Game *gameBoard){
    int userOption = startGame();
    switch (userOption) {
        case 0:
            break;
        case 1: // human against human
            printf("Starting Human against Human Game!\n");
            gameBoard->gameMode = GAMEMODE_HumanVsHuman;
            startHumanVsHuman(&gameBoard);
            break;
        case 2: // human against human
            printf("Starting Human against Computer Game!\n");
            gameBoard->gameMode = GAMEMODE_HumanVsComputer;
            startHumanVsBot(&gameBoard);
            break;
        default:
            printf("Please provide a valid option :(\n");
            initializeGame(gameBoard);
            break;
    }

}

int main() {
    // main game structure and players ( Global Variables )
    struct Game *gameBoard = NULL;
    gameBoard = malloc(sizeof(struct Game));
    cleanGameBoard(gameBoard);

    bool existGameFile = verifyGameRunningAfterExit();

    if(!existGameFile){
        initializeGame(gameBoard);
    }else{
        printf("============== ======= === ==============\n");
        printf("Game execution file detected, do you want to load the previous game? \n");
        printf("1 -> Yes\n");
        printf("0 -> No\n");
        printf("Your input selection: ");
        int userOption;
        scanf("%d",&userOption);
        printf("============== ======= === ==============\n");

        switch (userOption) {
            case 0:
                //delete the execution file
                deleteGameFileData();

                //initialize game
                initializeGame(gameBoard);
                break;
            case 1:
                //generate the game status based on the file
                loadGameFromSaveFile(gameBoard);
                break;
            default:
                main();
                break;
        }
    }

    return 0;
}

