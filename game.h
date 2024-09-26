#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef struct {
    Player **players;
    int playerCount;
    Board *board;
} ;

#endif
