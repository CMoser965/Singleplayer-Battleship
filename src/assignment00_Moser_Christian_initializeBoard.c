/**
 * Author: Christian Moser
 * Date: 08/28/21
 * Description: Create the board as a two-dimensional array and allocate memory for it; return the pointer for the board to be used later
 **/

#include "../include/assignment00_Moser_Christian_initializeBoard.h"

// function to initialize a 10 x 10 matrix with calloc()
int *initializeBoard() {

    int ROW_COL_DEF = 10;

    int *board = calloc((ROW_COL_DEF * ROW_COL_DEF), sizeof(int));

    return board;

}