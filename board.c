#include <stdio.h>
#include <stdlib.h>
#include "board.h"

Board* initBoard(int rows, int columns) {
    if (rows < 2 || columns < 2) {
        printf("La grille de jeux ne peut pas être plus petite que 2 x 2 !\n");
        // TODO 200 : call back menu to avoid crash
    }

    Board *board = malloc(sizeof(Board));

    if (board == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour la grille de jeux !\n");
    }

    // Set board value
    board->row = rows;
    board->column = columns;
    board->gameBoard = malloc(rows * sizeof(int *));

    // Init board matrix
    for (int i = 0; i < rows; i++) {
        board->gameBoard[i] = calloc(columns, sizeof(int));
    }

    // Print the game board
    // TODO DELETE
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", board->gameBoard[i][j]);
        }
        printf("\n");
    }

    return board;
}

void updateBoard(Board* board,int player,int column){
    for (int i = board->row - 1 ; i >= 0; i--)
    {
        if (board->gameBoard[i][column-1]==0)
        {
            board->gameBoard[i][column-1]= player; 
            break;
        }
        
    }
    
}
