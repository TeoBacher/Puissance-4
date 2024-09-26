#include <stdio.h>
#include "game.h"
#include "player.h"


// void game(Player player){
    
//     if (GridIsFull())
//     {
//         printf("Gris is full, equality");
//     }
    
//     int Column = SelectColumn();

//     player->playedTurnCounter += 1;

//     updateGrid();
//     DisplayGrid();
//     playerWin();
//     game(Player player);
// }


int main(void)
{
    int menu = 1;
    int isRunning = 0;
    printf("Puissance C\n");

    // Init menu
    while (menu)
    {
        int countPlayer;
        printf("Bienvenu dans le jeu 'PUISSANCE 4\n");
        scanf("");
        // fontion pour clear terminal

        // les joueur doivent donner speudo
        printf("Entrer le nombre de joueur : \n");
        scanf("->%d", &countPlayer);

        for (int i = 0; i < countPlayer; i++)
        {
            InitPlayer(i);
        }

        // Init grid (board)

        menu = 0;
        isRunning = 1;
    }

    // Game loop
    while (isRunning)
    {
        printf("Début du jeu\n");
        // Check if grid is full, if so, end game

        // for each player
        // ask  to select a column
        // check if column is valid
        // if not valid, ask again
        // if valid, play and update turn count
        // Update matrix && display grid
        // Check if player won

        // Repeat
    }
    return 0;
}
