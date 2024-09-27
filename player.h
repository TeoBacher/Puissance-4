#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char *color;
    char *name;
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
    END = 2,
    SIZE = 3
};

extern enum GameStatus currentStatus;

#endif
