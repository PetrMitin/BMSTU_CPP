#include "matchescontroller.h"

MatchesController::MatchesController(QString dbName, QString host, QString user, QString password) {
    this->db = QSqlDatabase::addDatabase("QPSQL");
    this->db.setDatabaseName(dbName);
    this->db.setHostName(host);
    this->db.setUserName(user);
    this->db.setPassword(password);
}

std::vector<Match> MatchesController::getAllMatches() {
    std::vector<Match> result;
    if(this->db.open()) {
        QSqlQuery getAll;
        if (getAll.exec("SELECT * FROM public.matches"))
            while(getAll.next())
                result.push_back(Match(getAll.value(0).toInt(), getAll.value(1).toString(), getAll.value(2).toString(), getAll.value(3).toString(), getAll.value(4).toInt(), getAll.value(5).toInt()));
    }
    this->db.close();
    return result;
}

bool MatchesController::addMatch(QString stadium, QString team1, QString team2, int team1Score, int team2Score) {
    bool ok = true;
    if(this->db.open()) {
        QSqlQuery addNew;
        addNew.prepare("INSERT INTO public.matches (\"stadium\", \"team1\", \"team2\", \"team1score\", \"team2score\") VALUES (?, ?, ?, ?, ?)");
        addNew.addBindValue(stadium);
        addNew.addBindValue(team1);
        addNew.addBindValue(team2);
        addNew.addBindValue(team1Score);
        addNew.addBindValue(team2Score);
        if (!addNew.exec()) ok = false;
    } else ok = false;
    this->db.close();
    return ok;
}

bool MatchesController::updateMatch(int matchId, QString stadium, QString team1, QString team2, int team1Score, int team2Score) {
    bool ok = true;
    if(this->db.open()) {
        QSqlQuery update;
        update.prepare("UPDATE public.matches SET stadium=:stadium, team1=:team1, team2=:team2, team1Score=:team1Score, team2Score=:team2Score WHERE matchId=:=matchId");
        update.bindValue(":stadium", stadium);
        update.bindValue(":team1", team1);
        update.bindValue(":team2", team2);
        update.bindValue(":team1Score", team1Score);
        update.bindValue(":team2Score", team2Score);
        if (!update.exec()) ok = false;
    } else ok = false;
    this->db.close();
    return ok;
}

bool MatchesController::deleteMatch(int matchId) {
    bool ok = true;
    if(this->db.open()) {
        QSqlQuery del;
        del.prepare("DELETE FROM public.matches WHERE matchId=:matchId");
        del.bindValue(":matchId", matchId);
        if (!del.exec()) ok = false;
    } else ok = false;
    this->db.close();
    return ok;;
}
