#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "matchescontroller.h"
#include "addmatchdialog.h"
#include "deletematchdialog.h"
#include "winsdialog.h"
#include "graphframe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showAllMatches();
    void addMatch();
    void deleteMatch();
    void filterByTeam();
    void filterByWins();
    void showDraws();
    void showGraph();
private:
    Ui::MainWindow *ui;
    MatchesController *matchesController;
    AddMatchDialog *addMatchDialog;
    DeleteMatchDialog *deleteMatchDialog;
    WinsDialog *winsDialog;
    GraphFrame* graphFrame;
    std::vector<Match> matches;
    QMap<QString, int> teams;
    void getAllMatches();
    void getTeamsWithWins();
    void fillComboBox();
    void showErrorMessage(QString text);
};
#endif // MAINWINDOW_H
