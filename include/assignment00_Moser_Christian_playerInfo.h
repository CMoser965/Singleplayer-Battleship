#ifndef PLAYERINFO_H
#define PLAYERINFO_H

struct PlayerInfo {
    char name[256];
    char country[256];
    char date[16];
    int score;
};

void playerInfo();

#endif