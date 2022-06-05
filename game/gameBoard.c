//
// Created by Jorge on 4/21/2022.
//

#include "gameBoard.h"
#include "utils.h"
#include <stdlib.h>

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
    game->gameFinished = false;

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

bool checkIfGameBoardIsValid(struct Game *game, int boardIndex){
    if(boardIndex > (TOTAL_BOARDS)-1 || boardIndex < 0)
        return false;
    else
        return true;
}

bool checkIfGameBoardIsFinished(struct Game *game, int boardIndex){
    if(game->boards[boardIndex].finished)
        return true;
    else
        return false;
}

/**
 * Verify if some one the players have won the respective game
 * @param game
 * @return
 */
void verifyBoardVictory(struct Game * game){
    printf("========== CURRENT GAME STATUS ==========\n\n");
    int i =0;
    struct Board b;
    for(i = 0; i < TOTAL_BOARDS; i++ ){
        int row = i / BOARD_MATRIX_ORDER;
        int column = i % BOARD_MATRIX_ORDER;

        if(game->boards[i].winner != NULL){
            struct Player boardWinner = *(game->boards[i].winner);
            b.board[row][column] = game->boards[i].winner->symbol;
            //printf("simbulo vencedor: %d , ",boardWinner.symbol);
            //printf("address : %p",&game->boards[i].winner);
            //printf("-> vencedor: do board %d : ",i);
            //displayString(game->boards[i].winner->name);
            //printf("\n");
        }else{

            b.board[row][column] = PLAYER_SYMBOL_NULL;
        }
    }
    b.winner = NULL;
    b.finished = false;
    displaySingleBoard(b);

    //verify by line
    bool winLine = VerifyPlayerWinByLine(&b);

    //verify by column
    bool winColumn = VerifyPlayerWinByColumn(&b);

    //verify by diag
    bool winDiag = VerifyPlayerWinByDiag(&b);

    //verify by diag inverted
    bool winDiagInverted = VerifyPlayerWinByDiagInverted(&b);

    if(winLine || winColumn || winDiag || winDiagInverted){
        game->gameFinished = true;
        game->currentlyPlaying->victories++;

        printf("Congratulations! The player ");
        displayString(game->currentlyPlaying);
        printf(" won the game!\n");
    }
    printf("============== ########### ==============\n");
}


struct UserPlay* getPlaysTailPointer(struct Game * game){
    if(game->boardPlays == NULL)
        return NULL;
    else{
        struct UserPlay *current = game->boardPlays;
        while(current->next != NULL){
            current = current->next;
        }
        return current;
    }
}

void registerPlay(struct Game *game, int boardNumber, int matrixIndex) {
    struct UserPlay *newPlay;
    newPlay = (struct UserPlay*) malloc(sizeof(struct UserPlay));

    newPlay->player = game->currentlyPlaying;
    newPlay->boardNumber = boardNumber;
    newPlay->matrixIndex = matrixIndex;
    newPlay->playNumber = game->playsCounter;
    newPlay->next = NULL;

    //if there isn't any board play
    if(game->boardPlays == NULL){
        game->boardPlays = newPlay;
        //printf(" > User play registered at the head of the linked-list [first-move]\n");
    }else{
        //find Tail and append to the tail new register
        struct UserPlay *tail = getPlaysTailPointer(game);
        tail->next = newPlay;
        //printf(" > User play registered at the tail of the linked-list\n");
    }
}

void displayAllPlays(struct Game *game){
    struct UserPlay *current = game->boardPlays;
    if(current != NULL){
        printf("[PLAYER MOVES] Listing all the moves made by the players\n");
        while(current != NULL && current->next != NULL){
            printf("[%d]: Board: [%d], Index: [%d] - ", current->playNumber,current->boardNumber,current->matrixIndex);
            displayString(current->player->name);
            printf("\n");
            current = current->next;
        }
    }
}

void displayPlays(struct Game *game,int total){
    struct UserPlay *current = game->boardPlays;
    int i = 1;
    if(current != NULL){
        while(current->next != NULL && i < total){
            printf("[%d]: Board: [%d], Index: [%d] - ", current->playNumber,current->boardNumber,current->matrixIndex);
            displayString(current->player->name);
            printf("\n");
            current = current->next;
            i++;
        }
    }
    free(current);
}
