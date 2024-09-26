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
        if (column <=0 || column >= board.column  )
        {
            printf("error");
            SelectColumn(board);
        }
        else{
            select = 1 ;
        }
    }
    return column;
    
}



void game(Player **listPlayer,Board board,int isRunning){

    while (isRunning)
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

    }
    
    //Update matrix
    //updateGrid();
    
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
        Player **listPlayer = malloc(sizeof(Player));

        int playerCount = 0;
        printf("Bienvenu dans le jeu 'PUISSANCE 4\n");

        // Number of player
        printf("Entrer le nombre de joueur : ");
        scanf("%d", &playerCount);

        // Min 2 players
        if (playerCount < 2)
        {
            printf("Il faut au moins 2 joueurs pour jouer\n");
            continue;
        } else if (playerCount > 6)
        {
            printf("Il ne peut y avoir plus de 6 joueurs\n");
            continue;
        }

        for (int i = 0; i < playerCount; i++)
        {
            listPlayer[i] = InitPlayer(i);
        }

        // Display player
        for (int i = 0; i < playerCount; i++)
        {
            printf("Joueur %d : %s\n", i+1, listPlayer[i]->name);
        }

        // Init board (default 6x7)
        Board board = initBoard(6,7);

        menu = 0;
        game(listPlayer, board ,isRunning);
        //isRunning = 1;
    }

    return 0;
}
