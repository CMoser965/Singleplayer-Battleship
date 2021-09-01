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
// forward declare ISR to access menu
void sighandler(int sig);

void play(int *board) {

    // define column as alphanumerical counterparts
    char col[] = "ABCDEFGHIJ";
    // define score
    int score = 100;
    // define a tracker to tell if ship x is destroyed;
    int tracker[5] = {0, 0, 0, 0, 0};
    // forward declare guess position, guess, ships destroyed tracker, and win condition
    int pos;
    char guess[2];
    int numOfDestroyedShips = 0;
    int gameIsWon = 5;
    

    while(numOfDestroyedShips != gameIsWon) {
    
        print(board);
        printf("Press CTRL - Z to access main menu. . .\n");
        printf("Enter guess: ");
        scanf("%s", guess);
        printf("\n");
        char *column = strchr(col, guess[0]);
        
        pos = (ROW_COL_DEF + (guess[1] - '0')) * (ROW_COL_DEF + (column - col));

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
                    printf("You sunk the Cruiser!\n");
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
    menu();
}

void print(int *board) {
    // clear the screen
    system("clear");

    
    // forward declare position indicator
    int pos;
    // print col indicator
    for(int i = 0; i < ROW_COL_DEF; i++) 
        printf(" " + (i+48));
    printf("\n");
    // print the board
    for(int i = 0; i < ROW_COL_DEF; i++) {
        // print row indicator
        printf((i+65) + " ");
        for(int j = 0; j < ROW_COL_DEF; j++) {
            pos = (i + ROW_COL_DEF)*(j + ROW_COL_DEF);
            switch(board[pos]) {
                case blank:
                    printf(" ");
                    break;
                case miss:
                    printf("M");
                    break;
                case hit:
                    printf("H");
            }
        }
        printf("\n");
    }
}

// ISR function that passes SIGTSTP signal launched from ^Z keybind to access menu()
void sighandler(int sig) {
    signal(SIGTSTP, sighandler);
    menu();
}