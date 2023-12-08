#ifndef MATCH_H
#define MATCH_H
#include <QString>

class Match
{
public:
    Match();

    Match(int _matchId, QString _stadium, QString _team1, QString _team2, int _team1Score, int _team2Score);

    int matchId;
    QString stadium;
    QString team1;
    QString team2;
    int team1Score;
    int team2Score;
};

#endif // MATCH_H
