#include <stdio.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

int *initializeBoard();
int ROW_COL_DEF;
void scoreBoard();
void play(int *board);
struct PlayerInfo {
    char name[256];
    char country[256];
    char date[16];
    int score;
};

void playerInfo();

int menu(int *board);

void exitOverride(int *board);
void scoreBoard();
void play(int *board);
void save(int score);
typedef enum {blank = 0, miss = 1, hit = 2, carrier = 100, battleship = 101, cruiser = 102, submarine = 103, destroyer = 104} 
boardState;

int CARRIER;
int BATTLESHIP;
int CRUISER;
int SUBMARINE;
int DESTROYER;
int ROW_COL_DEF;


int *populateBoard(int *board);

int main() {

	int *board;

	menu(board);

	return 0;
}
/** 
 *  Author: Christian Moser
 *  Date: 08/25/21
 *  Decription: Menu screen module to be used by single-player Battleship video game.
 *  
 *  Function: Act as a menu screen to allow user to navigate program, 
 * 	with error handling to prevent the user from doing something stupid, 
 *  like playing the game without an account, 
 *  or viewing a score board without a game running.
 **/

// menu method to be called by main function of program
int menu(int *board) {
	
	// Create a type bool -- short for boolean -- that will represent a
	// 0 if the value is false and 1 if the value is true
	typedef enum { false, true } bool;
	// Define the booleans to be used in order to allocate memory for case checking (out of scope errors, plus 
	// won't set off false false flags)
	bool playerInfoCreated = false;
	bool boardIsIntialized = false;
	bool boardIsPopulated = false;
	bool gameIsPlaying = false;

	while (true)
	{
		
		// Create point in program to send users back to 
		MENUSCREEN: ;
		
		const char *buffer;
		// Define choice to allocate memory	
		int choice;
		// clear the screen 
		printf("\n\n\n\n\n\n");
		// Create menu screen 
		printf("1. Enter player information\n");
		printf("2. Initialize the board\n");
		printf("3. Populate the board\n");
		printf("4. Play the game\n");
		printf("5. Print the board\n");
		printf("6. Score board\n");
		printf("7. Exit\n");
		// Populate integer "choice" address with value of 
		scanf("%d", &choice);

		// Switch statement to handle user input
		switch(choice) {

			// User wants to enter personal information
			case 1 :
				// Let them
				playerInfo();
				// make sure we remember they did that
				playerInfoCreated = true;
				// #JustCaseSwitchThings
				break;

			// User wants to initialize the board
			case 2 :
				// Check if user entered information
				if(!playerInfoCreated) {
					
					// if the user didn't enter information, don't let them initialize the board
					printf("You must first enter player information\n");
					// send them back to selection 
					goto MENUSCREEN;
				} else { 

					// Initialize the board
					board = initializeBoard();
					// Make sure we remember we did that
					boardIsIntialized = true;
				}
				// #JustCaseSwitchThings
				break;

			// User wants to populate the board
			case 3 :

			// Make sure they completed previous steps
				if(!playerInfoCreated || !boardIsIntialized) {
					// Find the specific error they made. If the player forgot to enter information, 
					// tell them. If they forgot to initialize the board, tell them. 
					buffer = (playerInfoCreated == false) ? "You cannot populate the board without first making an account and initilalizing the board." : "You must populate the board before first making an account.";
					// Print the condition
					printf("%s", buffer);
					goto MENUSCREEN;
				} else {
					// Populate the board
					printf("Line 100\n");
					int populateFlag = populateBoard(board);
					printf("Line 102\n");
					// Remember the user populated the board
					boardIsPopulated = true;
				}
				// #JustCaseSwitchThings
				break;
			
			// User wants to play the game 
			case 4 :
				
				// Check all conditions and let them know the specific issue they're having 
				if(!playerInfoCreated || !boardIsIntialized || !boardIsPopulated) {
				buffer = (playerInfoCreated == false) ? "You cannot play the game without first making an account, initilalizing the board, and populating the board, respectively." : boardIsIntialized ? "You must first populate the board to play the game." : "You must initialize the board before first making an account.";
					printf("%s", buffer);
					goto MENUSCREEN;
				} else {
					// . . .
					play(board);
					gameIsPlaying = true;
				}
				break;

			// User wants to print the board
			case 5 :

			// check all conditions and let them know the specific issue they're having
				if(!playerInfoCreated || !boardIsIntialized || !boardIsPopulated || !gameIsPlaying) {
					buffer = (playerInfoCreated == false) ? "You cannot print the board without first making an account, initilalizing the board, populating the board, and then starting a game. Obviously." : boardIsIntialized ? "You must first populate the board to print the game board." : !gameIsPlaying ? "You must start a game first" : "You must first initialize the board.";
					printf("%s", buffer);
					goto MENUSCREEN;
				} else {
					// . . .
					printPopulatedBoard(board);
				}
				break;

			// User wants to view the scoreboard. Operates exactly the same as case 5, but with different
			// buffer text (slightly altered) and calls scoreBoard() instead of printPopulatedBoard() 
			case 6 :
			
			// check all conditions
				if(!playerInfoCreated || !boardIsIntialized || !boardIsPopulated || !gameIsPlaying) {
					buffer = (playerInfoCreated == false) ? "You cannot view the scoreboard without first making an account, initilalizing the board, populating the board, and then starting a game. Obviously." : boardIsIntialized ? "You must first populate the board to view the scoreboard." : !gameIsPlaying ? "You must start a game first" : "You must first initialize the board.";
					printf("%s", buffer);
					goto MENUSCREEN;
				} else {
					// do the stuff
					scoreBoard();
				}
				// #JustCaseSwitchThings
				break;

			case 7 :
				// Send the flag that the menu has exited and we can stop the game
				exitOverride(board);
				break;
			default :
				printf("Please enter a valid option. . .\n");
				goto MENUSCREEN;
		}
	}
	return 0;
}

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
int* produce(int battleship, int *board, int carrier);

// ship detection before production
int *populateBoard(int *board) {

    printf("Line 30 populateBoard.c");
    // generate all the ships
    board = produce(CARRIER, board, carrier);
    board = produce(BATTLESHIP, board, battleship);
    board = produce(CRUISER, board, cruiser);
    board = produce(SUBMARINE, board, submarine);
    board = produce(DESTROYER, board, destroyer);

    // return populated board
    return board;
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

void playerInfo() {

    // create new file object
    FILE *profile;

    // open player file
    profile = fopen("playerInfo.dat", "w");

    // exits program if error is thrown
    if(profile == NULL) {
        fprintf(stderr, "\nError opend filed\n");
        exit(1);
    }
        
    // define variables for player info
    char playerName[256];
    char playerCountry[256];
    char gameDate[16];
    struct PlayerInfo player;
    
    // prompt user for name and save value
    printf("Enter your name: \n");
    scanf("%s", &playerName);
    printf("\n");

    // prompt user for country and save value
    printf("Enter your country origin: \n");
    scanf("%s", &playerCountry);
    printf("\n");

    // prompt user for date and save value
    printf("Enter today's date: \n");
    scanf("%s", &gameDate);
    printf("\n");

    // update struct player with player information
    *player.name = playerName;
    *player.country = playerCountry;
    *player.date = gameDate;
    player.score = NULL;

    // write out player information
    fwrite(&player, sizeof(struct PlayerInfo), 1, profile);

    // close the file
    fclose(profile);
}

// function to initialize a 10 x 10 matrix with calloc()
int *initializeBoard() {

    ROW_COL_DEF = 10;

    int *board = calloc((ROW_COL_DEF * ROW_COL_DEF), sizeof(int));

    return board;

}


void printPopulatedBoard(int *board) {
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
                    break;
                default:
                    printf("X");
            } 
        }
        printf("\n");
    }
}

void scoreBoard() {

    FILE *profile;
    fopen("playerInfo.dat", "r");

    if(profile == NULL) {
        fprintf(stderr, "\nError opend filed\n");
        exit(1);
    }

    struct PlayerInfo player;

    fread(&player, sizeof(struct PlayerInfo), 1, profile);

    printf("Name: %s", player.name);
    printf("\tCountry: %s", player.country);
    printf("\tScore: %s,", player.score);
}


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