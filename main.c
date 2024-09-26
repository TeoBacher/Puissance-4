#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "board.h"


int SelectColumn(Board board){
    int select;
    int column;
    while (select == 0)
    {
        printf("Select column : ");
        scanf("%s",column);
        if (column <=0 || column >= board.column)
        {
            if (board.gameBoard[0][column] =! 0)
            {
                printf("Column is full");
                continue;
            }
            else{
                printf("error");
            }
            continue;
        }
        else{
            select = 1 ;
        }
    }
    return column;
    
}



void game(Game *g, Board board, int isRunning){
 
    while (isRunning)
    {



        for (int i = 0; i < g->playerCount; i++)
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
            // Update matrix
            updateGrid(board, i, column);
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
        scanf("%d", g->playerCount);

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
        Board board = initBoard(6,7);

        menu = 0;
        game(g, board ,isRunning );
        //isRunning = 1;
    }

    return 0;
}
