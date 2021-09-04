/**
 * Author: Christian Moser
 * Date: 08/31/21
 * Description: Module to save the game during gameplay
 **/

#include <stdio.h>
#include "../include/assignment00_Moser_Christian_save.h"
#include "../include/assignment00_Moser_Christian_playerInfo.h"

// saves current game score w/ current player information
void save(int score) {

    // create file project
    FILE *profile;

    // open 
    profile = fopen("playerInfo.dat", "r+");

    if(profile == NULL) {
        fprintf(stderr, "\nError opend filed\n");
        exit(1);
    }
        
    // define variables for player info
    struct PlayerInfo player;

    // load current player info
    fread(&player, sizeof(struct PlayerInfo), 1, profile);

    // update score
    player.score = score;

    fwrite(&player, sizeof(struct PlayerInfo), 1, profile);

    // close the file
    fclose(profile);
}