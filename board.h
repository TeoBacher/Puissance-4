#ifndef BOARD_H
#define BOARD_H

#include "player.h"

typedef struct {
    int row;
    int column;
    int **gameBoard;
} Board;

Board initBoard(int rows, int columns);

void updateBoard( Board board,int player,int column);

#endif
