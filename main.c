#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "board.h"


int SelectColumn(Board* board){
    int select = 0;
    int column = 0;
    while (select == 0)
    {
        column = 0;

        // ask column to player
        printf("Select column : ");
        scanf("%d",&column);

        //  check if column is in matrix
        if (column <=0 || column >= board->column)
        {
            
                printf("error");
            continue;
        }
        // check if column is full
        else if (board->gameBoard[0][column] != 0)
        {
            printf("Column is full");
            continue;
        }
        else{
            select = 1 ;
        }
    }
    return column;
    
}



void game(Game *g, Board* board, int isRunning){
 
    while (isRunning)
    {



        for (int i = 1; i < g->playerCount; i++)
        {
                    // //    Check if grid is full
        // if (GridIsFull())
        // {
        //     // call function endgame()
        //     printf("Gris is full, equality");
        //     isRunning = 0;
        // }

            //Select column  
            int column = SelectColumn(board);

            printf("column : %d \n", column);
            // Update matrix
            updateBoard(board, i, column);

            for (int k = 0; k < board->row; k++)
            {
                for (int j = 0; j < board->column; j++)
                {
                    printf("%d ",board->gameBoard[k][j]);
                }
                printf("\n ");
            }
            
        }
    }
    

    //Display Board
    //DisplayGrid();

    // Check if player win
    //playerWin();

    // Repeat 
    //game(player, isRunning);
}


int main(void)
{
    int menu = 1;
    int isRunning = 0;

    // Init menu
    while (menu)
    {
        Game *g = malloc(sizeof(game));

        g->players = malloc(sizeof(Player)*6);

        printf("Bienvenu dans le jeu 'PUISSANCE 4\n");

        // Number of player
        printf("Entrer le nombre de joueur : ");
        scanf("%d", &g->playerCount);

        for (int i = 0; i < g->playerCount; i++)
        {
            g->players[i] = InitPlayer(i);
        }

        // Display player
        for (int i = 0; i < g->playerCount; i++)
        {
            printf("Joueur %d : %s\n", i, g->players[i]->name);
        }

        // Init board (default 6x7)
        Board* board = initBoard(6,7);

        menu = 0;
        isRunning = 1;
        game(g, board ,isRunning );
        
    }

    return 0;
}
