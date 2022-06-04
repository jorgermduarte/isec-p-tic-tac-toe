//
// Created by Jorge on 6/4/2022.
//

#include <stdlib.h>
#include <time.h>
#include "HumanVsBot.h"
#include "../player.h"
#include "../utils.h"

struct Player playerHuman, playerBot;



int BotAction_selectBoardIndex(struct Game *gameBoard){
    int x = rand() % TOTAL_BOARDS;
    struct Board findBoard = gameBoard->boards[x];
    if(findBoard.finished == false)
        return x;
    else
        BotAction_selectBoardIndex(gameBoard);
}

void private_startHumanVsBot(struct Game *gameBoard) {
    //define the board first player if it is NULL
    if (gameBoard->currentlyPlaying == NULL) {
        gameBoard->currentlyPlaying = gameBoard->players[0];
        printf("Defined the first player as: Player ");
        displayString(gameBoard->players[0]);
        printf("\n");
    }

    //ask first player in wich board index does he want to play is first move
    printf("=========================================\n");
    printf("Player ");
    displayString(gameBoard->currentlyPlaying->name);
    printf(", in wich board index do you want to play your move? \n");
    printf("Board Index: ");
    int boardIndex = 0;

    //check if the player is playing or is the bot instead
    if(gameBoard->currentlyPlaying->isBot){
        boardIndex = BotAction_selectBoardIndex(gameBoard);
    }else{
        scanf("%d", &boardIndex); //index of the game board
    }


    //while the current game(Tic Tac Toe) is running
    while (!gameBoard->gameFinished) {

        //Verify if the board index the user is trying to play really exists
        if (checkIfGameBoardIsValid(gameBoard, boardIndex)) {

            //If the board is already completed (last boardIndex), the user can select in wich board he wants to play
            while (gameBoard->boards[boardIndex].finished == true) {
                printf("\n The player before as put a selection in one board that is already finished. \n");
                printf("Select the new board you want to play your next move: ");

                //check if the player is playing or is the bot instead
                if(gameBoard->currentlyPlaying->isBot){
                    boardIndex = BotAction_selectBoardIndex(gameBoard);
                }else{
                    scanf("%d", &boardIndex);
                }
            }

            //check again if the boardIndex is valid because he could have entered the previous condition.
            if (!checkIfGameBoardIsValid(gameBoard, boardIndex)) { //if it is not valid
                private_startHumanVsBot(gameBoard);
            } else {
                // every condition is met and all parameters are valid
                // do the player action move
                boardIndex = playMove(gameBoard, &(gameBoard->boards[boardIndex]), &boardIndex);

                //define the next player to play
                if (gameBoard->currentlyPlaying == gameBoard->players[0])
                    gameBoard->currentlyPlaying = gameBoard->players[1];
                else
                    gameBoard->currentlyPlaying = gameBoard->players[0];
            }

        } else {
            // the user provided an invalid board index, invoke the function again
            printf("The board index provided by is invalid. Please provide a valid board index!\n");
            private_startHumanVsBot(gameBoard);
        }
    }
}

void startHumanVsBot(struct Game *gameBoard) {

    //Players initialization

    playerInitialization(&playerHuman, "One", PLAYER_SYMBOL_BALL,false);
    playerInitialization(&playerBot, "Bot", PLAYER_SYMBOL_X,true);

    displayPlayer(&playerHuman);
    displayPlayer(&playerBot);

    //set the board players;
    gameBoard->players[0] = &playerHuman;
    gameBoard->players[1] = &playerBot;

    //game display initialization
    cleanGameBoard(&gameBoard);
    displayGameBoard(&gameBoard);

    private_startHumanVsBot(gameBoard);
}

