#ifndef ADDMATCHDIALOG_H
#define ADDMATCHDIALOG_H

#include <QDialog>
#include "match.h"

namespace Ui {
class AddMatchDialog;
}

class AddMatchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMatchDialog(QWidget *parent = nullptr);
    ~AddMatchDialog();
    Match* getNewMatch();

public slots:
    void submitMatch();
    void close();

signals:
    void matchSubmitted();

private:
    Ui::AddMatchDialog *ui;
    void clearEdits();
};

#endif // ADDMATCHDIALOG_H
