#include <stdio.h>
#include <stdlib.h>
#include "player.h"

Player *InitPlayer(int nbrPlayer){
    char color[6] = {"\033[0;31m","\033[0;32m","\033[0;33m","\033[0;34m","\033[0;35m","\033[0;36m"};

    // malloc
    Player *player = malloc(sizeof(Player));
    player->name = malloc(sizeof(char)*30);

    // set variable
    player->color = color[nbrPlayer];
    scanf("Choissisez votre pseudo : %c", player->name);
    player->playedTurnCounter = 0;

    return player;
}



