//
// Created by Jorge on 4/21/2022.
//

#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include <stdio.h>
#include <stdbool.h>
#include "player.h"

#define BOARD_MATRIX_ORDER 3
#define TOTAL_BOARDS 9

typedef struct Board{
    int board[BOARD_MATRIX_ORDER][BOARD_MATRIX_ORDER];
    bool finished;
    struct Player *winner; // pointer to the winner player
};

typedef struct Game{
    int playsCounter;
    struct Board boards[TOTAL_BOARDS];
    struct Player *currentlyPlaying;
    struct Player *players[2];
};

/*
 * Verify if the game should end and if every board is finished
 */
//bool checkWinner(struct Game game);

/*
 * Verify if one player as won the game, and if yes,
 * set the winner of the board and invoke the board
 */
//struct Player checkBoardWinner(struct board b);

/*
 * Close one respective board ( finished = true )
 */
//bool closeBoard(struct board b);

void displaySingleBoard(struct Board board);

void displayGameBoard(struct Game *game);

void cleanGameBoard(struct Game *game);

bool checkIfGameBoardExistsOrIsFinished(struct Game *game, int boardIndex);

bool verifyBoardVictory(struct Game * game);

int startGame();

#endif //TIC_TAC_TOE_GAME_H
