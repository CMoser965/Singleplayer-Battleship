/**
 * Author: Christian Moser
 * Date: 08/31/2021
 * Description: Exits the program
 * **/

// function to exit program passes val to differentiate exit program
void exitOverride(int *board) {
    free(board);
    // exits
    _exit(0);
}