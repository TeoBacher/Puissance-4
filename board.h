#ifndef BOARD_H
#define BOARD_H

#include "player.h"

typedef struct {
    int row;
    int column;
    Player **state;
} Board;

#endif
