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

#include <stdio.h>
#include "../include/assignment00_Moser_Christian_playerInfo.h"
#include "../include/assignment00_Moser_Christian_initializeBoard.h"
#include "../include/assignment00_Moser_Christian_populateBoard.h"
#include "../include/assignment00_Moser_Christian_play.h"
#include "../include/assignment00_Moser_Christian_printPopulatedBoard.h"
#include "../include/assignment00_Moser_Christian_scoreBoard.h"
#include "../include/assignment00_Moser_Christian_exit.h"

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
					populateBoard(board);
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
				// if(!playerInfoCreated || !boardIsIntialized || !boardIsPopulated) {
				// 	buffer = (playerInfoCreated == false) ? "You cannot print the board without first making an account, initilalizing the board, populating the board, and then starting a game. Obviously." : !boardIsIntialized ? "You must first populate the board to print the game board." : "You must first initialize the board.";
				// 	printf("%s", buffer);
				// 	goto MENUSCREEN;
				// } else {
					// . . .
					printPopulatedBoard(board);
				// }
				break;

			// User wants to view the scoreboard. Operates exactly the same as case 5, but with different
			// buffer text (slightly altered) and calls scoreBoard() instead of printPopulatedBoard() 
			case 6 :
					scoreBoard();
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
