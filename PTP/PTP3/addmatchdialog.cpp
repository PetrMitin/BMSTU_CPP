#include "addmatchdialog.h"
#include "ui_addmatchdialog.h"
AddMatchDialog::AddMatchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMatchDialog)
{
    ui->setupUi(this);
    connect(this->ui->submitButton, SIGNAL(clicked(bool)), this, SLOT(submitMatch()));
    connect(this->ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}
AddMatchDialog::~AddMatchDialog() {
    delete ui;
}
Match* AddMatchDialog::getNewMatch() {
    bool team1ScoreValid;
    bool team2ScoreValid;
    QString stadium = this->ui->stadiumEdit->text();
    QString team1 = this->ui->team1Edit->text();
    QString team2 = this->ui->team2Edit->text();
    int team1Score = this->ui->team1ScoreEdit->text().toInt(&team1ScoreValid);
    int team2Score = this->ui->team2ScoreEdit->text().toInt(&team2ScoreValid);
    Match* result;
    if (!team1ScoreValid || !team2ScoreValid || team1Score < 0 || team2Score < 0 || !stadium.length() || !team1.length() || !team2.length()) {
        result = new Match();
    } else result = new Match(-1, stadium, team1, team2, team1Score, team2Score);
    return result;
}

void AddMatchDialog::clearEdits() {
    this->ui->stadiumEdit->clear();
    this->ui->team1Edit->clear();
    this->ui->team2Edit->clear();
    this->ui->team1ScoreEdit->clear();
    this->ui->team2ScoreEdit->clear();
}

void AddMatchDialog::submitMatch() {
    emit this->matchSubmitted();
    this->clearEdits();
}

void AddMatchDialog::close() {
    this->clearEdits();
    QDialog::close();
}
