#include "deleteitemdialog.h"
#include "ui_deleteitemdialog.h"

DeleteItemDialog::DeleteItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteItemDialog)
{
    ui->setupUi(this);
    connect(this->ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(deleteItem()));
    connect(this->ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(close()));
}

int DeleteItemDialog::getIndexToDelete() {
    bool *ok = new bool(true);
    int result = this->ui->lineEdit->text().toInt(ok);
    if (!*ok) result = -1;
    delete ok;
    return result;
}

void DeleteItemDialog::deleteItem() {
    emit this->itemDeleted();
}

void DeleteItemDialog::close() {
    this->ui->lineEdit->clear();
    QWidget::close();
}

DeleteItemDialog::~DeleteItemDialog()
{
    delete ui;
}
