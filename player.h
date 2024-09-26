#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char *color;
    char *name;
    int playedTurnCounter;

    // Optional
    int score;
} Player;

#endif
