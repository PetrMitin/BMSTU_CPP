#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include "item.h"

namespace Ui {
class addItemDialog;
}

class addItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addItemDialog(QWidget *parent = nullptr);
    ~addItemDialog();

    Item getItemData();

    void clearEdits();

public slots:
    void close();

    void submitItem();
signals:
    void itemSubmitted();

private:
    Ui::addItemDialog *ui;
};

#endif // ADDITEMDIALOG_H
