#include <stdio.h>
#include <stdlib.h>
#include "board.h"

Board* initBoard(int rows, int columns, int length) {
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
    board->length = length;
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

void updateBoard(Board* board, int player, int column){
    // Go to the bottom of the column
    for (int i = board->row - 1 ; i >= 0; i--)
    {
        if (board->gameBoard[i][column-1]==0)
        {
            board->gameBoard[i][column-1]= player; 
            isWin(board, player);
            break;
        }
    } 
}

// Win detection
int isWin(Board* board, int player) {

    printf("Win check for : %d\n", player);

    // Horizontal check
    for (int row = 0; row < board->row; row++) {
        for (int col = 0; col <= board->column - board->length; col++) {
            int count = 0;
            for (int i = 0; i < board->length; i++) {
                if (board->gameBoard[row][col + i] == player) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == board->length) {
                printf("Player %d win by horizontal !\n", player);
                return 1;
            }
        }
    }

    // Vertical check
    for (int col = 0; col < board->column; col++) {
        for (int row = 0; row <= board->row - board->length; row++) {
            int count = 0;
            for (int i = 0; i < board->length; i++) {
                if (board->gameBoard[row + i][col] == player) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == board->length) {
                printf("Player %d win by vertical !\n", player);
                return 1;
            }
        }
    }

    // Diagonal check (bottom-left)
    for (int row = 0; row <= board->row - board->length; row++) {
        for (int col = 0; col <= board->column - board->length; col++) {
            int count = 0;
            for (int i = 0; i < board->length; i++) {
                if (board->gameBoard[row + i][col + i] == player) {
                    count++;
                } else {
                    printf("Player %d win by diagonal !\n", player);
                    break;
                }
            }
            if (count == board->length) {
                return 1;
            }
        }
    }

    // Vérification diagonale (haut-droite)
    for (int row = board->length - 1; row < board->row; row++) {
        for (int col = 0; col <= board->column - board->length; col++) {
            int count = 0;
            for (int i = 0; i < board->length; i++) {
                if (board->gameBoard[row - i][col + i] == player) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == board->length) {
                printf("Player %d win by diagonal !\n", player);
                return 1;
            }
        }
    }

    return 0;
}