/**
 * Author: Christian Moser
 * Date: 08/29/21
 * Description: Module used to generate battleships
 * **/

#include "../include/assignment00_Moser_Christian_populateBoard.h"
#include "../include/assignment00_Moser_Christian_initializeBoard.h"
#include <time.h>
#include <stdio.h>

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

    return;
}

// function to generate battleships
void produce(int battleship, int *board, int token) {
    // generate a random number range 1--4 to specify randomely generated orientation
    int orientation = (rand() % 1) + 1;
    // printf(orientation);
    // the intercept coefficient is used to randomely generated the second
    //dimension of placement (i.e., if left/right, generates random y-dimension)
    int interceptCoeff = (rand() % ROW_COL_DEF);
    // first occupied space of battleship
    int head = (rand() % (9));
    printf("head (starting unit for %d): %d\nintercept coeffeciant: %d\n", battleship, head, interceptCoeff);

    int positionGeneration, i;
    // loop used to occupy board
    for(i = 0; i < battleship; i++) {
        switch(orientation){
            // left orientation
            case 1:
                positionGeneration = ROW_COL_DEF * (head - i) + interceptCoeff;
                break;
            // right orientation
            case 2:
                positionGeneration = ROW_COL_DEF * (head + i) + interceptCoeff;
                break;
            // up orientation
            case 3:
                positionGeneration = ROW_COL_DEF * head + (interceptCoeff - i);
                break;
            // down orientation
            case 4:
                positionGeneration = ROW_COL_DEF * head + (interceptCoeff + i);
        }
        printf("Generated location: %d\n", positionGeneration);
        board[positionGeneration] = token;
    }

    // return
    return;
}