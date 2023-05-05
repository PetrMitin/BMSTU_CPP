#include <QMessageBox>
#include "additemdialog.h"
#include "ui_additemdialog.h"

addItemDialog::addItemDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::addItemDialog) {
    ui->setupUi(this);
    connect(this->ui->submitButton, SIGNAL(clicked(bool)), this, SLOT(submitItem()));
    connect(this->ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

addItemDialog::~addItemDialog() {
    delete ui;
}

void addItemDialog::clearEdits() {
    this->ui->nameEdit->clear();
    this->ui->amountEdit->clear();
    this->ui->priceEdit->clear();
}

void addItemDialog::submitItem() {
    emit this->itemSubmitted();
    this->clearEdits();
}

Item addItemDialog::getItemData() {
    bool *validPrice, *validAmount;
    validPrice = new bool(true);
    validAmount = new bool(true);
    QString name = this->ui->nameEdit->text();
    float price = this->ui->priceEdit->text().toFloat(validPrice);
    int amount = this->ui->amountEdit->text().toInt(validAmount);
    if (!(*validPrice) || !(*validAmount) || amount < 0 || price < 0 || !name.length()) {
        return Item("");
    }
    delete validPrice;
    delete validAmount;
    return Item(name, price, amount);
}

void addItemDialog::close() {
    this->clearEdits();
    QWidget::close();
}
