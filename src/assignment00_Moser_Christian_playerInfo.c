/**
 * Author: Christian Moser
 * Date: 8/25/21
 * Description: Module allows user to enter player information
 **/

#include <stdio.h>
#include "../include/assignment00_Moser_Christian_playerInfo.h"

void playerInfo() {

    // create new file object
    FILE *profile;

    // open player file
    profile = fopen("playerInfo.dat", "r+");

    // creates file if first time running
    if(profile == NULL) {
        profile = fopen("playerInfo.dat", "w+");
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
    strcpy(player.name, playerName);
    strcpy(player.country, playerCountry);
    strcpy(player.date, gameDate);
    player.score = NULL;

    // write out player information
    fwrite(&player, sizeof(struct PlayerInfo), 1, profile);

    // close the file
    fclose(profile);
}