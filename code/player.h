#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char *color;
    char *name;
    char *token;
    int playedTurnCounter;

    // Optional
    int score;
} Player;

Player *InitPlayer(int nbrPlayer);

void freePlayer(Player *player);

enum GameStatus
{
    START = 0,
    PLAY = 1,
    WIN = 2,
    EQUALITY = 3,
    END = 4,
};

extern enum GameStatus currentStatus;

#endif
