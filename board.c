#include <stdio.h>
#include <stdlib.h>
#include "board.h"


void initBoard(int rows, int columns) {
    if (rows < 2 || columns < 2) {
        printf("La grille de jeux ne peut pas être plus petite que 2 x 2 !\n");
        // TODO 200 : call back menu to avoid crash
    }

    Board *board = malloc(sizeof(Board));

    if (board == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour la grille de jeux !\n");
    }

    // Set board size
    board->row = rows;
    board->column = columns;

    // Build the game board
    int **gameBoard = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        gameBoard[i] = malloc(columns * sizeof(int));
    }

    // Print the game board
    // TODO DELETE
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", gameBoard[i][j]);
        }
        printf("\n");
    }
}
