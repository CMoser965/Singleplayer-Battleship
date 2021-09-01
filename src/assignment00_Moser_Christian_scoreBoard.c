/**
 * Author: Christian Moser
 * Date: 08/28/21
 * Description: Model displays player information accumulated over history of game.
 **/

#include <stdio.h>
#include "../include/assignment00_Moser_Christian_playerInfo.h"

void scoreBoard() {

    FILE *profile;
    fopen("playerInfo.dat", "r");

    if(profile == NULL) {
        fprintf(stderr, "\nError opend filed\n");
        exit(1);
    }

    struct PlayerInfo player;

    fread(&player, sizeof(struct PlayerInfo), 1, profile);

    printf("Name: " + *player.name);
    printf("\tCountry: " + *player.country);
    printf("\tScore: " + player.score);
}