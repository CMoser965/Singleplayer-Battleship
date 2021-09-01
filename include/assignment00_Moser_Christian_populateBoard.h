typedef enum {blank = 0, miss = 1, hit = 2, carrier = 100, battleship = 101, cruiser = 102, submarine = 103, destroyer = 104} boardState;

int CARRIER = 5;
int BATTLESHIP = 4;
int CRUISER = 3;
int SUBMARINE = 3;
int DESTROYER = 2;


int *populateBoard(int *board);