#ifndef DELETEITEMDIALOG_H
#define DELETEITEMDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteItemDialog;
}

class DeleteItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteItemDialog(QWidget *parent = nullptr);
    ~DeleteItemDialog();

    int getIndexToDelete();

public slots:
    void deleteItem();

    void close();
signals:
    void itemDeleted();

private:
    Ui::DeleteItemDialog *ui;
};

#endif // DELETEITEMDIALOG_H
