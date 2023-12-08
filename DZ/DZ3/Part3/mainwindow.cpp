#include <QtSql>
#include <QMessageBox>
#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->items = Items();
    this->changedItems = {};

    //add item modal
    this->createItemDialog = new addItemDialog(this);
    this->createItemDialog->hide();
    this->createItemDialog->setModal(true);

    //delete item modal
    this->deleteItemDialog = new DeleteItemDialog(this);
    this->deleteItemDialog->hide();
    this->deleteItemDialog->setModal(true);

    this->fillTableWidget();
    connect(this->ui->pushButton, SIGNAL(clicked(bool)), this->createItemDialog, SLOT(show()));
    connect(this->createItemDialog, SIGNAL(itemSubmitted()), this, SLOT(createItem()));
    connect(this->ui->pushButton_2, SIGNAL(clicked(bool)), this->deleteItemDialog, SLOT(show()));
    connect(this->deleteItemDialog, SIGNAL(itemDeleted()), this, SLOT(deleteItem()));
    connect(this->ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(updateItems()));
    connect(this->ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void MainWindow::fillTableWidget() {
    this->ui->tableWidget->setRowCount(0);
    int counter = 0;
    for (auto& item : this->items.getAllItems()) {
        this->ui->tableWidget->insertRow(counter);
        this->ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(item.name));
        this->ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(QString::number(item.price)));
        this->ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(QString::number(item.amount)));
        counter++;
    }
}

void MainWindow::showErrorMessage(QString text) {
    QMessageBox errorMessage;
    errorMessage.setText(text);
    errorMessage.exec();
}

void MainWindow::createItem() {
    Item newItem = this->createItemDialog->getItemData();
    if (newItem.name.length() == 0) this->showErrorMessage("Invalid data provided!");
    else {
        this->items.addItem(newItem.name, newItem.price, newItem.amount);
        this->fillTableWidget();
    }
    this->createItemDialog->close();
}

void MainWindow::updateItems() {
    int counter = 0;
    for (auto& item : this->items.getAllItems()) {
        QString currName = this->ui->tableWidget->item(counter, 0)->text();
        float currPrice = this->ui->tableWidget->item(counter, 1)->text().toFloat();
        int currAmount = this->ui->tableWidget->item(counter, 2)->text().toInt();
        if (currName == item.name && (item.price != currPrice || item.amount != currAmount))
            if(!this->items.updateItem(currName, currPrice, currAmount)) {
                this->showErrorMessage("Update error!");
                break;
            }
        counter++;
    }
    this->fillTableWidget();
}

void MainWindow::deleteItem() {
    int indexToDelete = this->deleteItemDialog->getIndexToDelete();
    if (indexToDelete == -1 || indexToDelete >= this->ui->tableWidget->rowCount()) this->showErrorMessage("Invalid index provided!");
    else {
        QString name = this->ui->tableWidget->itemAt(indexToDelete, 0)->text();
        this->items.deleteItem(name);
        this->fillTableWidget();
    }
    this->deleteItemDialog->close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete createItemDialog;
    delete deleteItemDialog;
}
