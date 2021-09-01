/**
 * Author: Christian Moser
 * Date: 08/29/21
 * Description: Module used to generate battleships
 * **/

#include <time.h>
#include <stdio.h>
#include "../include/assignment00_Moser_Christian_populateBoard.h"
#include "../include/assignment00_Moser_Christian_initializeBoard.h"


// define constants to be used in battleship generation
CARRIER = 5;
BATTLESHIP = 4;
CRUISER = 3;
SUBMARINE = 3;
DESTROYER = 2;
ROW_COL_DEF = 10;

// define boardState data types in header
// typedef boardState;

// function to return board with generated battleship
void produce(int battleship, int *board, int carrier);

// ship detection before production
void populateBoard(int *board) {
    
    // generate all the ships
    produce(CARRIER, board, carrier);
    produce(BATTLESHIP, board, battleship);
    produce(CRUISER, board, cruiser);
    produce(SUBMARINE, board, submarine);
    produce(DESTROYER, board, destroyer);
}

// function to generate battleships
void produce(int battleship, int *board, int token) {
    // generate a random number range 1--4 to specify randomely generated orientation
    int orientation = (srand(time(0)) % 4) + 4;
    // the intercept coefficient is used to randomely generated the second
    //dimension of placement (i.e., if left/right, generates random y-dimension)
    int interceptCoeff = (srand(time(0)) % ROW_COL_DEF) + ROW_COL_DEF - 1;
    // first occupied space of battleship
    int head = (srand(time(0)) % battleship) + battleship - 1;

    // loop used to occupy board
    for(int i = 0; i < CARRIER; i++) {
        switch(orientation){
            // left orientation
            case 1:
                board[((i + head) * interceptCoeff)] = token;
                break;
            // right orientation
            case 2:
                board[((i - head) * interceptCoeff)] = token;
                break;
            // up orientation
            case 3:
                board[(head * (i + interceptCoeff))] = token;
                break;
            // down orientation
            case 4:
                board[((i + head) * (i + interceptCoeff))] = token;
        }
    }
}