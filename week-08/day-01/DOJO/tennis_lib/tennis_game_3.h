#ifndef TENNIS_GAME_TENNIS_GAME_3_H
#define TENNIS_GAME_TENNIS_GAME_3_H

typedef struct {
    int player1Score;
    int player2Score;
    char *player1Name;
    char *player2Name;
} tennis_game_3_t;

tennis_game_3_t create_tennis_game_3(const char *player1Name, const char *player2Name);

void won_point_3(tennis_game_3_t *tennisGame, const char *playerName);

const char *get_score_3(tennis_game_3_t *tennisGame);

#endif //TENNIS_GAME_TENNIS_GAME_3_H