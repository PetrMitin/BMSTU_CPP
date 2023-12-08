#ifndef MATCHESCONTROLLER_H
#define MATCHESCONTROLLER_H
#include <QtSql>
#include "match.h"
#include <vector>

class MatchesController
{
public:
    MatchesController(QString dbName="ptp3sem2", QString host="127.0.0.1", QString user="postgres", QString password="150600Pm");

    std::vector<Match> getAllMatches();

    bool addMatch(QString stadium, QString team1, QString team2, int team1Score, int team2Score);

    bool updateMatch(int matchId, QString stadium, QString team1, QString team2, int team1Score, int team2Score);

    bool deleteMatch(int matchId);

private:
    QSqlDatabase db;
};

#endif // MATCHESCONTROLLER_H
