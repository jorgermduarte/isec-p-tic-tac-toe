//
// Created by Jorge on 4/22/2022.
//

#include <stdio.h>
#include "player.h"
#include "utils.h"
#include <math.h>

/**
 *
 * @param b
 * @return returns the index that the user played,
 * its used to reference the next board dependency if the board is not completed yet.
 */
int playMove(struct Game *gameBoard,struct Board *b,int *boardIndex){

    printf("> Player Playing: ");
    displayString(gameBoard->currentlyPlaying->name);
    printf("| Playing on board: %d\n",*boardIndex);
    printf("In witch index do you want to play?");
    int playIndex = -1;
    scanf("%d",&playIndex);

    //verify if the play index the user is trying to play really exists;
    int limitIndex = pow(BOARD_MATRIX_ORDER,2) -1;
    if(playIndex > limitIndex || playIndex < 0){
        printf("Please provide a valid index based on the current game\n");
        printf("The index's must be between 0 and %d \n",limitIndex);
        playIndex = playMove(gameBoard,b,boardIndex);
    }

    int row = playIndex / BOARD_MATRIX_ORDER;
    int column = playIndex % BOARD_MATRIX_ORDER;

    //check if that board number is already occupied
    if(gameBoard->boards[*boardIndex].board[row][column] == PLAYER_SYMBOL_BALL ||
            gameBoard->boards[*boardIndex].board[row][column] == PLAYER_SYMBOL_X){
        printf("You provided a invalid index that is already occupied :( Please try again \n");
        playIndex = playMove(gameBoard,b,boardIndex);
    }else{
        //update board position
        printf("Updating board %d with index %d, row: %d col: %d\n",*boardIndex,playIndex,row,column);
        b->board[row][column] = gameBoard->currentlyPlaying->symbol;

        displayGameBoard(gameBoard);
    }

    //todo - verify if the board ended ( someone won )

    //returns the index that the player played in that board to affect the next move
    return playIndex;
}

void playerInitialization(struct Player *player,char *playerName, enum PlayerSymbolCode psc){
    int i = 0;

    while (*playerName != '\0'){
        player->name[i] = *playerName;
        playerName++;
        i++;
    }

    player->defeats = 0;
    player->victories = 0;
    player->symbol = psc;
}


void displayPlayer(struct Player *player){

    printf("=========================================\n");
    printf("Player Name: ");
    int charI = 0;
    while(player->name[charI] != '\0'){
        printf("%c",player->name[charI]);
        charI++;
    }
    printf("\n");
    printf("Player Victories: %d\n",player->victories);
    printf("Player Defeats: %d\n", player->defeats);
    printf("Player Symbol Code Number: %d\n",player->symbol);
    printf("=========================================\n\n");
}
