#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "board.h"

// free all game
void freeGame(Game *g){
    for (int i = 0; i < g->playerCount; i++)
    {
        freePlayer(g->players[i]);
    }
    freeBoard(g->board);
    free(g);
}

// Select column
int SelectColumn(Board* board){
    int select = 0;
    int column = 0;
    while (select == 0)
    {
        column = 0;

        // ask column to player
        printf("  Sélectionnez une colonne : ");
        scanf("%d",&column);

        //  check if column is in matrix
        if (column <=0 || column >= board->column)
        { 
            printf("La colonne n'est pas dans la grille !\n");
            continue;
        }
        // check if column is full
        else if (board->gameBoard[0][column] != 0)
        {
            printf("La colonne est pleine, veuillez en choisir une autre !");
            continue;
        }
        else{
            select = 1 ;
        }
    }
    system("clear");
    return column;
}

void game(Game *g){
 
    while (currentStatus == PLAY)
    {
        for (int i = 1; i <= g->playerCount; i++)
        {
            if (currentStatus == END)
            {
                break;
            }
            
            if (isBoardFull(g->board))
            {
                printf("Gris is full, equality");
                currentStatus = END;
            }

            printf("\n");

            for (int i = 0; i < g->board->column; i++)
            {
                printf("=====");
            }
            
            printf("\n\n  C'est au tour de %d : %s, votre signe est : ", i, g->players[i-1]->name);
            printf("%s", g->players[i-1]->color);
            printf("%s\n", g->players[i-1]->token);
            printf("\033[0;37m");

            //Select column  
            int column = SelectColumn(g->board);

            // Update matrix
            updateBoard(g->board, i, column);

            //Display Board
            displayBoard(g->players, g->board);
            
        }
    }

    if (currentStatus == END)
    {
        system("clear");
        printf("Game Over\n");
        freeGame(g);
        printf("Play again ?\n 1 : Yes\n 2 : No\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            currentStatus = START;
            break;
        case 2:
            printf("Goodbye\n");
            break;
        default:
            printf("Wrong choice, goodbye!\n");
            break;
        }
    }
}

int main()
{
    // Init menu
    while (currentStatus == START)
    {
        Game *g = malloc(sizeof(game));
        g->players = malloc(sizeof(Player)*6);

        system("clear");
        printf("Bienvenu(e) dans PUISSANCE C !\n\n");

        // Number of player
        printf("Entrer le nombre de joueur : ");
        scanf("%d", &g->playerCount);

        for (int i = 0; i < g->playerCount; i++)
        {
            g->players[i] = InitPlayer(i);
        }

        system("clear");

        // Init board (default 6x7)
        g->board = initBoard(6, 7, 4);

        // Display board
        displayBoard(g->players, g->board);

        currentStatus = PLAY;
        game(g);
        
    }

    return 0;
}
