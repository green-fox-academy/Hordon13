#include "tennis_game_3.h"
#include <string.h>
#include <stdlib.h>

tennis_game_3_t create_tennis_game_3(const char *player1Name, const char *player2Name)
{
    tennis_game_3_t result = {0, 0, calloc(strlen(player1Name) + 1, 1), calloc(strlen(player2Name) + 1, 1)};
    strcpy(result.player1Name, player1Name);
    strcpy(result.player2Name, player2Name);
    return result;
}

void won_point_3(tennis_game_3_t *tennisGame, const char *playerName)
{
    strcmp(playerName, "player1") ? tennisGame->player2Score++ : tennisGame->player1Score++;
}

const char *get_score_3(tennis_game_3_t *tennisGame)
{
    char *score;

    if (tennisGame->player1Score < 4 && tennisGame->player2Score < 4) {
        static const char *point[] = {"Love", "Fifteen", "Thirty", "Forty"};
        char tempScore[20];
        strcpy(tempScore, point[tennisGame->player1Score]);
        if (tennisGame->player1Score == tennisGame->player2Score) {
            strcat(tempScore, "-All");
        } else {
            strcat(tempScore, "-");
            strcat(tempScore, point[tennisGame->player2Score]);
        }
        score = calloc(strlen(tempScore) + 1, sizeof(char));
        strcpy(score, tempScore);
        return score;

    } else {
        if (tennisGame->player1Score == tennisGame->player2Score)
            return "Deuce";

        char tempScore[20];
        (tennisGame->player1Score > tennisGame->player2Score) ? strcpy(tempScore, tennisGame->player1Name) : strcpy(
                tempScore, tennisGame->player2Name);

        char tempScore2[15];
        ((tennisGame->player1Score - tennisGame->player2Score) *
         (tennisGame->player1Score - tennisGame->player2Score) == 1) ? strcpy(tempScore2, "Advantage ") : strcpy(
                tempScore2, "Win for ");

        score = calloc(strlen(tempScore) + strlen(tempScore2) + 1, sizeof(char));
        strcpy(score, tempScore2);
        strcat(score, tempScore);
        return score;
    }
}