#ifndef DELETEMATCHDIALOG_H
#define DELETEMATCHDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteMatchDialog;
}

class DeleteMatchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteMatchDialog(QWidget *parent = nullptr);
    ~DeleteMatchDialog();
    int getMatchId();

public slots:
    void deleteMatch();
    void close();

signals:
    void matchDeleted();

private:
    Ui::DeleteMatchDialog *ui;
};

#endif // DELETEMATCHDIALOG_H
