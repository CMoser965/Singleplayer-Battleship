/**
 * Author: Christian Moser
 * Date: 08/28/21
 * Description: Create the board as a two-dimensional array and allocate memory for it; return the pointer for the board to be used later
 **/

#include <stdlib.h>
#include "../include/assignment00_Moser_Christian_initializeBoard.h"

// function to initialize a 10 x 10 matrix with calloc()
int *initializeBoard() {

    ROW_COL_DEF = 10;
    int *board = calloc(100, sizeof(int));
    return board;

}