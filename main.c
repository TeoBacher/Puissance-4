#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "player.h"

void game(Player *player){

    //Check if grid is full
    // if (GridIsFull())
    // {
    //     printf("Gris is full, equality");
    //     isRunning = 0;
    // }

    //Select column  
    //int Column = SelectColumn();

    // Upgrade turn number player
    player->playedTurnCounter += 1;

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
    //int isRunning = 0;

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
        initBoard(6, 7);

        menu = 0;
        //isRunning = 1;
    }

    // Game loop
    // while (isRunning)
    // {
    //     printf("Début du jeu\n");
        //game();

        // Check if grid is full, if so, end game

        // for each player
        // ask  to select a column
        // check if column is valid
        // if not valid, ask again
        // if valid, play and update turn count
        // Update matrix && display grid
        // Check if player won

        // Repeat
    //}
    return 0;
}
