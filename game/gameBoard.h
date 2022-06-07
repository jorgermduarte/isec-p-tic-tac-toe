//
// Created by Jorge on 4/21/2022.
//

#ifndef TIC_TAC_TOE_GAMEBOARD_H
#define TIC_TAC_TOE_GAMEBOARD_H

#include <stdio.h>
#include <stdbool.h>
#include "player.h"

#define FILE_NAME_SAVE_GAME "jogo.bin"
#define FILE_NAME_VICTORY "victory.txt"
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
    bool wonBoard; // if the player on the board based on this move
    bool boardClosed; // if the board was  based on this move
    struct Player *player;
    struct UserPlay *next;
    struct UserPlay *previous;
};


typedef enum PlayerSymbolCodeFile{
    FILE_PLAYER_SYMBOL_NULL = 0,
    FILE_PLAYER_SYMBOL_BALL = 1,
    FILE_PLAYER_SYMBOL_X = 2,
};

typedef struct PlayerFile{
    char name[5];
    int victories;
    int defeats;
    enum PlayerSymbolCodeFile symbol; // if the player is the O,X ou another symbol
    bool isBot;
};

typedef struct UserPlayFile{
    int playNumber; // the play number that auto-increments
    int boardNumber; // the game board number
    int matrixIndex; // the matrix tic tac toe index
    bool wonBoard; // if the player on the board based on this move
    bool boardClosed; // if the board was  based on this move
    struct PlayerFile player;
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


void registerPlay(struct Game *game, int boardNumber, int matrixIndex,bool wonBoard, bool boardClosed);

void displayLastNPlays(struct Game *game,int total);

void displayAllPlays(struct Game *game);


void saveCurrentGameStatus(struct Game *game);

void loadGameStatusFromFile();


void saveGameVictory(struct Game *game, char *filename);


bool verifyGameRunningAfterExit();

void deleteGameFileData();

void loadGameFromSaveFile(struct Game *game);

#endif //TIC_TAC_TOE_GAMEBOARD_H
