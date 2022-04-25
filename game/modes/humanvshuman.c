//
// Created by Jorge on 4/25/2022.
//

#include "humanvshuman.h"
#include "../player.h";
#include "../utils.h"

struct Player player1, player2;

void startGameHumanVsHuman(struct Game *gameBoard) {
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
    printf(", in wich board index do you want to play your first move? \n");
    printf("Board Index: ");
    int boardIndex = 0;
    scanf("%d", &boardIndex); //index of the game board

    //while the current game(Tic Tac Toe) is running
    while (!gameBoard->gameFinished) {

        //Verify if the board index the user is trying to play really exists
        if (checkIfGameBoardIsValid(gameBoard, boardIndex)) {

            //If the board is already completed (last boardIndex), the user can select in wich board he wants to play
            while (gameBoard->boards[boardIndex].finished == true) {
                printf("\n The player before as put a selection in one board that is already finished. \n");
                printf("Select the new board you want to play your next move: ");
                scanf("%d", &boardIndex);
            }

            //check again if the boardIndex is valid because he could have entered the previous condition.
            if (!checkIfGameBoardIsValid(gameBoard, boardIndex)) { //if it is not valid
                startGameHumanVsHuman(gameBoard);
            } else {
                // every condition is met and all parameters are valid
                // do the player action move
                boardIndex = playMove(gameBoard, &(gameBoard->boards[boardIndex]), &boardIndex);

                //define the next player to play
                if(gameBoard->currentlyPlaying == gameBoard->players[0])
                    gameBoard->currentlyPlaying = gameBoard->players[1];
                else
                    gameBoard->currentlyPlaying = gameBoard->players[0];
            }

        }else{
            // the user provided an invalid board index, invoke the function again
            printf("The board index provided by is invalid. Please provide a valid board index!\n");
            startGameHumanVsHuman(gameBoard);
        }
    }
}

void startHumanVsHuman(struct Game *gameBoard){
    //Players initialization
    playerInitialization(&player1,"One",PLAYER_SYMBOL_BALL);
    playerInitialization(&player2,"Two",PLAYER_SYMBOL_X);

    displayPlayer(&player1);
    displayPlayer(&player2);

    //set the board players;
    gameBoard->players[0] = &player1;
    gameBoard->players[1] = &player2;

    //game display initialization
    cleanGameBoard(&gameBoard);
    displayGameBoard(&gameBoard);

    startGameHumanVsHuman(gameBoard);
}


