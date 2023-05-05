#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <vector>
#include "items.h"
#include "additemdialog.h"
#include "deleteitemdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showErrorMessage(QString text);

public slots:
    void createItem();

    void updateItems();

    void deleteItem();

private:
    Ui::MainWindow *ui;
    Items items;
    addItemDialog *createItemDialog;
    DeleteItemDialog *deleteItemDialog;
    std::vector<Item> changedItems;

    void fillTableWidget();
};
#endif // MAINWINDOW_H
