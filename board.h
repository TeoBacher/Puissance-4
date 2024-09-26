#ifndef BOARD_H
#define BOARD_H

#include "player.h"

typedef struct {
    int row;
    int column;
    int length;
    int **gameBoard;
} Board;

Board* initBoard(int rows, int columns, int length);

void updateBoard(Board* board,int player,int column);

int isWin(Board* board, int player);

#endif
