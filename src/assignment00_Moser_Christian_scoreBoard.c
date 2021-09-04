/**
 * Author: Christian Moser
 * Date: 08/28/21
 * Description: Model displays player information accumulated over history of game.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "../include/assignment00_Moser_Christian_playerInfo.h"


void scoreBoard() {

    FILE *profile;
    profile = fopen("playerInfo.dat", "r");

    if(profile == NULL) {
        fprintf(stderr, "\nError opend filed\n");
        exit(1);
    }

    struct PlayerInfo player;

    while(fread(&player, sizeof(struct PlayerInfo), 1, profile)) {
    printf("Name: %s", player.name);
    printf("\t\t\t\t\tCountry: %s", player.country);
    printf("\t\t\t\t\tDate: %s", player.date);
    printf("\t\t\t\t\tScore: %d\n", player.score);
    }
}