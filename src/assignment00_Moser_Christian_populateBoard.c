/**
 * Author: Christian Moser
 * Date: 08/29/21
 * Description: Module used to generate battleships
 * **/

#include "../include/assignment00_Moser_Christian_populateBoard.h"

// define constants to be used in battleship generation
int CARRIER = 5;
int BATTLESHIP = 4;
int CRUISER = 3;
int SUBMARINE = 3;
int DESTROYER = 2;
int ROW_COL_DEF = 10;

// define boardState data types
typedef enum {blank = 0, miss = 1, hit = 2, carrier = 100, battleship = 101, cruiser = 102, submarine = 103, destroyer = 104} boardState;

// function to return board with generated battleship
int* produce(int battleship);

// TODO:
// ship detection before production
int *populateBoard(int *board) {

    // generate all the ships
    *board = produce(CARRIER, *board, carrier);
    *board = produce(BATTLESHIP, *board, battleship);
    *board = produce(CRUISER, *board, cruiser);
    *board = produce(SUBMARINE, *board, submarine);
    *board = produce(DESTROYER, *board, destroyer);

    // return populated board
    return *board;
}

// function to generate battleships
int* produce(int battleship, int *board, int token) {
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

    // return populated board
    return *board;
}