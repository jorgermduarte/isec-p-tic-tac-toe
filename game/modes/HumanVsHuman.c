//
// Created by Jorge on 4/25/2022.
//

#include "HumanVsHuman.h"

#include "../utils.h"
#include <stdlib.h>

void private_startGameHumanVsHuman(struct Game *gameBoard,bool skip, int newBoardIndex) {
    int boardIndex = 0;
    if(!skip){
        //define the board first player if it is NULL
        if (gameBoard->currentlyPlaying == NULL) {
            gameBoard->currentlyPlaying = gameBoard->players[0];
            printf("Defined the first player as: Player ");
            displayString(gameBoard->players[0]);
            printf("\n");
        }

        //ask first player in wich board index does he want to play is first move
        printf("=========================================\n");
        printf("Player %s, in wich board index do you want to play your move? \n", gameBoard->currentlyPlaying->name);
        printf("Board Index: ");
        scanf("%d", &boardIndex); //index of the game board
    }else{
        boardIndex = newBoardIndex;
    }

    //while the current game(Tic Tac Toe) is running
    while (!gameBoard->gameFinished) {

        printf("======== What do you want to do ==========\n");
        printf("1 -> Play\n");
        printf("2 -> List last N game moves\n");
        printf("============ ============== ===============\n");
        printf("Your input selection: ");
        int userSelectionOp;
        scanf("%d",&userSelectionOp);


        if(userSelectionOp == 1){
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
                    private_startGameHumanVsHuman(gameBoard,false,0);
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
                private_startGameHumanVsHuman(gameBoard,false,0);
            }
        }else if(userSelectionOp == 2){
            int totalMoves = 0;
            printf("How many last moves do you want to see?\n");
            scanf("%d",&totalMoves);
            displayLastNPlays(gameBoard,totalMoves);
        }
    }

    if(gameBoard->gameFinished){
        deleteGameFileData();
        saveGameVictory(gameBoard);
    }
}

void startHumanVsHuman(struct Game *gameBoard) {
    //Players initialization
    //struct Player defaultdata;
    struct Player *ptr1;
    struct Player *ptr2;
    ptr1 = (struct Player*) malloc(sizeof(struct Player));
    ptr2 = (struct Player*) malloc(sizeof(struct Player));

    char *pname1;
    char *pname2;

    //game display initialization
    cleanGameBoard(gameBoard);

    printf("Please provide the player one name: \n");
    scanf("%s", &pname1);

    printf("Please provide the player two name: \n");
    scanf("%s", &pname2);

    playerInitialization(ptr1,&pname1,PLAYER_SYMBOL_BALL,false);
    playerInitialization(ptr2,&pname2,PLAYER_SYMBOL_X,false);

    displayPlayer(ptr1);
    displayPlayer(ptr2);

    //set the board players;
    gameBoard->players[0] = ptr1;
    gameBoard->players[1] = ptr2;

    displayGameBoard(gameBoard);

    private_startGameHumanVsHuman(gameBoard,false,0);


}



