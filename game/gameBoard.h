//
// Created by Jorge on 4/21/2022.
//

#ifndef TIC_TAC_TOE_GAMEBOARD_H
#define TIC_TAC_TOE_GAMEBOARD_H

#include <stdio.h>
#include <stdbool.h>
#include "player.h"

#define BOARD_MATRIX_ORDER 3
#define TOTAL_BOARDS 9

enum GameMode{
    GAMEMODE_HumanVsHuman = 0,
    GAMEMODE_HumanVsComputer = 1
};

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
    enum GameMode gameMode;
    bool gameFinished;
    struct UserPlay *boardPlays;
};;

typedef struct UserPlay{
    int playNumber; // the play number that auto-increments
    int boardNumber; // the game board number
    int matrixIndex; // the matrix tic tac toe index
    struct Player *player;
    struct UserPlay *next;
    struct UserPlay *previous;
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

bool checkIfGameBoardIsFinished(struct Game *game, int boardIndex);

bool checkIfGameBoardIsValid(struct Game *game, int boardIndex);

void verifyBoardVictory(struct Game * game);

int startGame();


void registerPlay(struct Game *game, int boardNumber, int matrixIndex);

void displayLastNPlays(struct Game *game,int total);

void displayAllPlays(struct Game *game);


#endif //TIC_TAC_TOE_GAMEBOARD_H
