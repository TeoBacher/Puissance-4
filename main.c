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



void game(Game *g, int isRunning){
 
    while (isRunning)
    {



        for (int i = 1; i <= g->playerCount; i++)
        {
                    // //    Check if grid is full
        // if (GridIsFull())
        // {
        //     // call function endgame()
        //     printf("Gris is full, equality");
        //     isRunning = 0;
        // }

            printf("Player %d : %s\n", i, g->players[i-1]->name);

            //Select column  
            int column = SelectColumn(g->board);

            printf("column : %d \n", column);
            // Update matrix
            updateBoard(g->board, i, column);

            for (int k = 0; k < g->board->row; k++)
            {
                for (int j = 0; j < g->board->column; j++)
                {
                    printf("%d ",g->board->gameBoard[k][j]);
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
        g->board = initBoard(6, 7, 4);

        menu = 0;
        isRunning = 1;
        game(g,isRunning);
        
    }

    return 0;
}
