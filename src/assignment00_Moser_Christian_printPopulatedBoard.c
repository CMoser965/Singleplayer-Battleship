/**
 * Author: Christian Moser
 * Date: 08/31/2021
 * Description: Prints the populated board
 * 
**/

#include <stdio.h>
#include "../include/assignment00_Moser_Christian_populateBoard.h"

void printPopulatedBoard(int *board) {
    // clear the screen
    system("clear");

    
    // forward declare position indicator
    int pos;
    // print col indicator
    for(int i = 0; i < ROW_COL_DEF; i++) 
        printf("%d ", i);
    printf("\n");
    // print the board
    for(int i = 0; i < ROW_COL_DEF; i++) {
        // print row indicator
        printf("%c",(i+65));
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
                    break;
                default:
                    printf("X");
            } 
        }
        printf("\n");
    }
}