#include <stdio.h>
#include "game/game.h";

// main game structure and players ( Global Variables )
struct Game gameBoard;
struct Player player1, player2;


void startHumanVsHumanBoard(){
    bool gameEnded = false;

    printf("Player One in witch board index do you want to play your first move?\n");
    printf("Board Index: ");
    int boardIndex = 0;
    scanf("%d",&boardIndex); //index of the game board

    while(!gameEnded){
        //Verify if the board index the user is trying to play really exists
        if(checkIfGameBoardExistsOrIsFinished(&gameBoard,boardIndex)){

            if(gameBoard.currentlyPlaying == NULL){
                gameBoard.currentlyPlaying = gameBoard.players[0];
                boardIndex = playMove(&gameBoard,&gameBoard.boards[boardIndex],&boardIndex);
            }else {

                //Based on the board conditions it can be not the last boardIndex
                //basically its based on if the board is already completed ( last boardIndex), the user can select
                //in wich board he wants to play
                if (gameBoard.boards[boardIndex].finished == true) {
                    printf("\n The player before as put a selection in one board that is already finished\n");
                    printf("Select the new board you want to play your next move: ");
                    scanf("%d", &boardIndex);
                }

                if (checkIfGameBoardExistsOrIsFinished(&gameBoard, boardIndex)) {
                    if (gameBoard.currentlyPlaying == gameBoard.players[0]) {
                        gameBoard.currentlyPlaying = gameBoard.players[1];
                    } else {
                        gameBoard.currentlyPlaying = gameBoard.players[0];
                    }
                    boardIndex = playMove(&gameBoard, &gameBoard.boards[boardIndex], &boardIndex);
                } else {
                    // the user provided a invalid board index
                    // invoke this function again
                    printf("Please provide a valid board index!\n");
                    startHumanVsHumanBoard();
                }
            }
        }else{
            // the user provided a invalid board index
            // invoke the function again
            printf("Please provide a valid board index!\n");
            startHumanVsHumanBoard();
        }

        //Verify if on the outside boards game someone won
        //set the gameEnded as true;
        //apply the victory to the respective player;
        //apply the defeat to the respective player;
        gameEnded = verifyBoardVictory(&gameBoard);
    }
}

void startHumanVsHuman(){

    playerInitialization(&player1,"One",PLAYER_SYMBOL_BALL);
    playerInitialization(&player2,"Two",PLAYER_SYMBOL_X);

    displayPlayer(&player1);
    displayPlayer(&player2);

    //game display initialization
    cleanGameBoard(&gameBoard);
    displayGameBoard(&gameBoard);

    //set the board players;
    gameBoard.players[0] = &player1;
    gameBoard.players[1] = &player2;

    startHumanVsHumanBoard();

}

int main() {
    int userOption = startGame();
    switch (userOption) {
        case 0:
            break;
        case 1: // human against human
            printf("Starting Human against Human Game!\n");
            startHumanVsHuman();
            break;
        default:
            printf("Please provide a valid option :(\n");
            main();
            break;
    }
    return 0;
}
