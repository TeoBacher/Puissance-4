#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "player.h"

// Enum for game status
enum GameStatus currentStatus;

// Max length player name
#define MAX_NAME_LENGTH 29 

void freePlayer(Player *player) {
    free(player->name);
    free(player);
}

// Check if the name contains only alphanumeric characters
int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        // Check if the character is not alphanumeric
        if (!isalnum(name[i])) {
            return 0;
        }
    }
    return 1;
}

// Clear the screen
void clearScreen() {
    system("clear");
}

Player *InitPlayer(int nbrPlayer) {
    // Tab of color
    char *color[] = {"\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m"};

    // Add dynamic memory for player
    Player *player = malloc(sizeof(Player));
    if (!player) {
        perror("Erreur d'allocation mémoire pour le joueur");
        exit(EXIT_FAILURE);
    }

    // Add dynamic memory for player name
    player->name = malloc(sizeof(char) * (MAX_NAME_LENGTH + 1));
    if (!player->name) {
        perror("Erreur d'allocation mémoire pour le nom du joueur");
        free(player);
        exit(EXIT_FAILURE);
    }

    // Get player name
    int valid = 0;
    while (!valid) {
        printf("Choisissez votre pseudo (maximum %d caractères, uniquement lettres et/ou chiffres) : ", MAX_NAME_LENGTH);
        scanf("%s", player->name);

        // Delete the \n
        size_t len = strlen(player->name);
        if (len > 0 && player->name[len - 1] == '\n') {
            player->name[len - 1] = '\0';
        }

        // Check if empty
        if (strlen(player->name) == 0) {
            clearScreen();
            printf("Le pseudo ne peut pas être vide. Veuillez réessayer.\n");
            continue;
        }

        // Check if too long
        if (strlen(player->name) > MAX_NAME_LENGTH) {
            clearScreen();
            printf("Le pseudo est trop long. Veuillez limiter à %d caractères.\n", MAX_NAME_LENGTH);
            continue;
        }

        // Check if only alphanumeric
        if (!isValidName(player->name)) {
            clearScreen();
            printf("Le pseudo ne doit contenir que des lettres et des chiffres.\n");
            continue;
        }

        valid = 1;
    }

    // Set player color
    player->color = color[nbrPlayer];

    // Init player turn counter
    player->playedTurnCounter = 0;

    return player;
}
