/**
 * Author: Christian Moser
 * Date: 08/29/21
 * Description:  Module used to play the game
 * 
 * **/

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "../include/assignment00_Moser_Christian_play.h"
#include "../include/assignment00_Moser_Christian_initializeBoard.h"
#include "../include/assignment00_Moser_Christian_populateBoard.h"
#include "../include/assignment00_Moser_Christian_save.h"
#include "../include/assignment00_Moser_Christian_menu.h"

// forward declare print func
void print(int *board);

void play(int *board) {

    // define column as alphanumerical counterparts
    char col[] = "ABCDEFGHIJ";
    // define score
    int score = 100;
    int gameStillRunning = 0;
    // define a tracker to tell if ship x is destroyed;
    int tracker[5] = {0, 0, 0, 0, 0};
    // forward declare guess position, guess, ships destroyed tracker, and win condition
    int pos;
    char guess[2];
    int numOfDestroyedShips = 0;
    int gameIsWon = 5;
    

    while(numOfDestroyedShips != gameIsWon) {
        
        print(board);
        printf("Enter guess: ");
        scanf("%s", guess);
        printf("\n");
        int rowGuess = guess[0] - 'A';
        
        // cheat code to instantly beat game
        if(strcmp(guess, "pihselttab") == 0) 
            numOfDestroyedShips = gameIsWon;

        pos = (guess[1] - '0') + ROW_COL_DEF * rowGuess;

        switch(board[pos]) {

            case cruiser:
                board[pos] = hit;
                printf("Cruiser hit!\n");
                tracker[cruiser - 100]++;
                if(tracker[cruiser - 100] == CRUISER) {
                    printf("You sunk the Cruiser!\n");
                    numOfDestroyedShips++;
                }
                break;
            
            case battleship:
                board[pos] = hit;
                printf("Battleship hit!\n");
                tracker[battleship - 100]++;
                if(tracker[battleship - 100] == BATTLESHIP) {
                    printf("You sunk the Battleship!\n");
                    numOfDestroyedShips++;
                }
                break;
            
            case carrier:
                board[pos] = hit;
                printf("Carrier hit!\n");
                tracker[carrier - 100]++;
                if(tracker[carrier - 100] == CARRIER) {
                    printf("You sunk the Carrier!\n");
                    numOfDestroyedShips++;
                }
                break;
            
            case submarine:
                board[pos] = hit;
                printf("Submarine hit!\n");
                tracker[submarine - 100]++;
                if(tracker[submarine - 100] == SUBMARINE) {
                    printf("You sunk the Submarine!\n");
                    numOfDestroyedShips++;
                }
                break;
            
            case destroyer:
                board[pos] = hit; 
                printf("Destroyer hit!\n");
                tracker[destroyer - 100]++;
                if(tracker[destroyer - 100] == DESTROYER) {
                    printf("You sunk the Destroyer!\n");
                    numOfDestroyedShips++;
                }
                break;

            case hit:
                printf("You cannot target the same space twice.\n");
                break;

            default:
                board[pos] = miss;
                printf("You missed!\n");
                score--;
        }

    }
    printf("Game over!\n");
    save(score);
    menu(board);
}

void print(int *board) {
 
    // forward declare position indicator
    int pos;
    // print col indicator
    printf("  ");
    for(int i = 0; i < ROW_COL_DEF; i++) 
        printf("%d", i);
    printf("\n");
    // print the board
    for(int i = 0; i < ROW_COL_DEF; i++) {
        // print row indicator
        printf("%c ",(i+65));
        for(int j = 0; j < ROW_COL_DEF; j++) {
            pos = (i * ROW_COL_DEF) + j;
            switch(board[pos]) {
                    break;
                case miss:
                    printf("M");
                    break;
                case hit:
                    printf("H");
                    break;
                default:
                    printf("O");
            } 
        } 
        printf("\n");
    } 
}