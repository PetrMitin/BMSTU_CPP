#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->matchesController = new MatchesController();

    this->addMatchDialog = new AddMatchDialog(this);
    this->addMatchDialog->hide();
    this->addMatchDialog->setModal(true);

    this->deleteMatchDialog = new DeleteMatchDialog(this);
    this->deleteMatchDialog->hide();
    this->deleteMatchDialog->setModal(true);

    this->winsDialog = new WinsDialog(this);
    this->winsDialog->hide();
    this->winsDialog->setModal(true);

    this->graphFrame = new GraphFrame(this);
    this->graphFrame->hide();

    this->getAllMatches();
    this->fillComboBox();

    this->showAllMatches();

    connect(this->ui->showAllButton, SIGNAL(clicked(bool)), this, SLOT(showAllMatches()));
    connect(this->ui->addNewButton, SIGNAL(clicked(bool)), this->addMatchDialog, SLOT(show()));
    connect(this->addMatchDialog, SIGNAL(matchSubmitted()), this, SLOT(addMatch()));
    connect(this->ui->deleteButton, SIGNAL(clicked(bool)), this->deleteMatchDialog, SLOT(show()));
    connect(this->deleteMatchDialog, SIGNAL(matchDeleted()), this, SLOT(deleteMatch()));
    connect(this->ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(filterByTeam()));
    connect(this->ui->winsButton, SIGNAL(clicked(bool)), this->winsDialog, SLOT(show()));
    connect(this->winsDialog, SIGNAL(winsEntered()), this, SLOT(filterByWins()));
    connect(this->ui->drawsButton, SIGNAL(clicked(bool)), this, SLOT(showDraws()));
    connect(this->ui->graphButton, SIGNAL(clicked(bool)), this, SLOT(showGraph()));
    connect(this->ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->matchesController;
}

void MainWindow::showErrorMessage(QString text) {
    QMessageBox errorMessage;
    errorMessage.setText(text);
    errorMessage.exec();
}

void MainWindow::getAllMatches() {
    this->matches = this->matchesController->getAllMatches();
}

void MainWindow::getTeamsWithWins() {
    this->teams.clear();
    for (auto& match : this->matches) {
        if (this->teams.contains(match.team1)) match.team1Score > match.team2Score ? this->teams[match.team1]++ : false;
        else this->teams.insert(match.team1, match.team1Score > match.team2Score ? 1 : 0);
        if (this->teams.contains(match.team2)) match.team2Score > match.team1Score ? this->teams[match.team2]++ : false;
        else this->teams.insert(match.team2, match.team2Score > match.team1Score ? 1 : 0);
    }
}

void MainWindow::fillComboBox() {
    this->getTeamsWithWins();
    this->ui->comboBox->clear();
    this->ui->comboBox->addItem("-No Team-");
    this->ui->comboBox->addItems(this->teams.keys());
    this->ui->comboBox->setCurrentIndex(0);
}

void MainWindow::showAllMatches() {
    this->ui->comboBox->setCurrentIndex(0);
    QStringList columnLabels {"Match Id", "Stadium", "Team 1", "Team 2", "Team 1 Score", "Team 2 Score"};
    this->ui->tableWidget->setColumnCount(6);
    this->ui->tableWidget->setHorizontalHeaderLabels(columnLabels);
    this->ui->tableWidget->setRowCount(0);
    int counter = 0;
    for (auto& match : this->matches) {
        this->ui->tableWidget->insertRow(counter);
        this->ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::number(match.matchId)));
        this->ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(match.stadium));
        this->ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(match.team1));
        this->ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(match.team2));
        this->ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(QString::number(match.team1Score)));
        this->ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(QString::number(match.team2Score)));
        counter++;
    }
}

void MainWindow::addMatch() {
    Match* newMatch = this->addMatchDialog->getNewMatch();
    if (!newMatch->stadium.length()) {
        this->showErrorMessage("Invalid data!");
    } else {
        bool ok = this->matchesController->addMatch(newMatch->stadium, newMatch->team1, newMatch->team2, newMatch->team1Score, newMatch->team2Score);
        if (!ok) this->showErrorMessage("Error during writing to db!");
        else {
            this->addMatchDialog->close();
            this->getAllMatches();
            this->showAllMatches();
            this->fillComboBox();
        }
    }
}

void MainWindow::deleteMatch() {
    int matchId = this->deleteMatchDialog->getMatchId();
    if (matchId == -1) this->showErrorMessage("Invalid data!");
    else {
        bool ok = this->matchesController->deleteMatch(matchId);
        if (!ok) this->showErrorMessage("Error! Unable to delete match with such id!");
        else {
            this->deleteMatchDialog->close();
            this->getAllMatches();
            this->showAllMatches();
            this->fillComboBox();
        }
    }
}

void MainWindow::filterByTeam() {
    QString team = this->ui->comboBox->currentText();
    if (team == "-No Team-") this->showAllMatches();
    else {
        this->ui->tableWidget->setRowCount(0);
        int counter = 0;
        for (auto& match : this->matches) {
            if (match.team1 == team || match.team2 == team) {
                this->ui->tableWidget->insertRow(counter);
                this->ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::number(match.matchId)));
                this->ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(match.stadium));
                this->ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(match.team1));
                this->ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(match.team2));
                this->ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(QString::number(match.team1Score)));
                this->ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(QString::number(match.team2Score)));
                counter++;
            }
        }
    }
}

void MainWindow::filterByWins() {
    int wins = this->winsDialog->getWins();
    if (wins == -1) this->showErrorMessage("Invalid data!");
    else {
        QStringList columnLabels {"Team", "Wins"};
        this->ui->tableWidget->setColumnCount(2);
        this->ui->tableWidget->setHorizontalHeaderLabels(columnLabels);
        this->ui->tableWidget->setRowCount(0);
        int counter = 0;
        for (QString& key : this->teams.keys()) {
            if (this->teams[key] >= wins) {
                this->ui->tableWidget->insertRow(counter);
                this->ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(key));
                this->ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(QString::number(this->teams[key])));
                counter++;
            }
        }
        if (counter == 0) {
            this->showErrorMessage("No teams with that many wins!");
            this->showAllMatches();
        }
    }
    this->winsDialog->close();
}

void MainWindow::showDraws() {
    this->ui->tableWidget->setRowCount(0);
    int counter = 0;
    for (auto& match : this->matches) {
        if (match.team1Score == match.team2Score) {
            this->ui->tableWidget->insertRow(counter);
            this->ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::number(match.matchId)));
            this->ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(match.stadium));
            this->ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(match.team1));
            this->ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(match.team2));
            this->ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(QString::number(match.team1Score)));
            this->ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(QString::number(match.team2Score)));
            counter++;
        }
    }
}

void MainWindow::showGraph() {
    this->graphFrame->fillChart(this->matches);
    this->graphFrame->show();
}
