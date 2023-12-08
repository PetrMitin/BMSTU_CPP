#ifndef WINSDIALOG_H
#define WINSDIALOG_H

#include <QDialog>

namespace Ui {
class WinsDialog;
}

class WinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinsDialog(QWidget *parent = nullptr);
    ~WinsDialog();
    int getWins();

public slots:
    void enterWins();
    void close();

signals:
    void winsEntered();

private:
    Ui::WinsDialog *ui;
};

#endif // WINSDIALOG_H
