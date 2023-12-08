#include "match.h"

Match::Match()
    : matchId(-1),
    stadium(""),
    team1(""),
    team2(""),
    team1Score(0),
    team2Score(0) {}

Match::Match(int _matchId, QString _stadium, QString _team1, QString _team2, int _team1Score, int _team2Score)
    : matchId(_matchId),
    stadium(_stadium),
    team1(_team1),
    team2(_team2),
    team1Score(_team1Score),
    team2Score(_team2Score)
{}
