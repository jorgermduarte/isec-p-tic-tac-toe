//
// Created by Jorge on 4/21/2022.
//

#include "game.h"

void displaySingleBoard(struct Board target){
    int column,line;
    for(line =0; line < BOARD_MATRIX_ORDER;line++){
        for(column = 0; column < BOARD_MATRIX_ORDER; column++){
            printf(" %c ", target.board[line][column] == PLAYER_SYMBOL_NULL ? '-' :
                           target.board[line][column] == PLAYER_SYMBOL_BALL ? '0' : 'X'
            );
        }
        printf("\n");
    }
    printf("\n");
}

void displayGameBoards(struct Board boards[TOTAL_BOARDS], int startIndex){
    int i,breakLine = 0,bl = 0,bc = 0;
    int boardIndex = 0;
    while(bl < BOARD_MATRIX_ORDER){
        printf("|| ");
        for(i = startIndex; i < (startIndex+BOARD_MATRIX_ORDER);i++){
            struct Board currentBoard = boards[i];
            for(bc = 0; bc < BOARD_MATRIX_ORDER; bc++){
                printf(" %c ", currentBoard.board[bl][bc] == PLAYER_SYMBOL_NULL ? '-' :
                    currentBoard.board[bl][bc] == PLAYER_SYMBOL_BALL ? '0' : 'X'
                );
            }
            printf(" || ");
        }
        printf("\n");
        breakLine++;
        bl++;

        if(breakLine >= BOARD_MATRIX_ORDER){
            //printf("\n");
            printf("-----------------------------------------\n");
        }

    }
    //printf("startindex: %d , ended: %d \n",startIndex,startIndex+BOARD_MATRIX_ORDER);

    if(startIndex < TOTAL_BOARDS-BOARD_MATRIX_ORDER)
        displayGameBoards(boards,(startIndex+BOARD_MATRIX_ORDER));

}

void displayGameBoardsValues(struct Board boards[TOTAL_BOARDS], int startIndex){
    int i,breakLine = 0,bl = 0,bc = 0;
    int boardIndex = 0;
    while(bl < BOARD_MATRIX_ORDER){
        printf("|| ");
        for(i = startIndex; i < (startIndex+BOARD_MATRIX_ORDER);i++){
            struct Board currentBoard = boards[i];
            for(bc = 0; bc < BOARD_MATRIX_ORDER; bc++){
                printf(" %d ", currentBoard.board[bl][bc]);
            }
            printf(" || ");
        }
        printf("\n");
        breakLine++;
        bl++;

        if(breakLine >= BOARD_MATRIX_ORDER){
            //printf("\n");
            printf("-----------------------------------------\n");
        }

    }
    //printf("startindex: %d , ended: %d \n",startIndex,startIndex+BOARD_MATRIX_ORDER);

    if(startIndex < TOTAL_BOARDS-BOARD_MATRIX_ORDER)
        displayGameBoards(boards,(startIndex+BOARD_MATRIX_ORDER));

}

void displayGameBoard(struct Game *game){
    int i,x;
    printf("============== TIC TAC TOE ==============\n");
    displayGameBoards(game->boards,0);
    printf("============== ########### ==============\n");
}

void cleanGameBoard(struct Game *game){
    int i;
    int x,y;
    for(i = 0; i < TOTAL_BOARDS; i++){
        game->boards[i].finished = false;
        game->boards[i].winner = NULL;
        //clean board itself
        // 0 = '-'
        for(x = 0; x < BOARD_MATRIX_ORDER; x++){
            for(y = 0; y < BOARD_MATRIX_ORDER; y++){
                game->boards[i].board[x][y] = 0;
            }
        }
    }
    game->currentlyPlaying = NULL;
}

int startGame(){
    printf("======== Ultimate Tic Tac Toe ==========\n");
    printf("# Game modes # \n");
    printf("1 -> 2 Human Players \n");
    printf("2 -> Play against the PC\n");
    printf("0 -> Exit\n");
    printf("============ a2021110042 ===============\n");
    printf("Your input selection: ");
    int userOption;
    scanf("%d",&userOption);

    return userOption;
}

bool checkIfGameBoardExistsOrIsFinished(struct Game *game, int boardIndex){
    if(boardIndex > (TOTAL_BOARDS)-1 || boardIndex < 0)
        return false;
    if(game->boards[boardIndex].finished)
        return false;
    else
        return true;
}

/**
 * Verify if some one the players have won the respective game
 * @param game
 * @return
 */
bool verifyBoardVictory(struct Game * game){
    //set the gameEnded as true;
    //apply the victory to the respective player;
    //apply the defeat to the respective player;
    return false;
}
