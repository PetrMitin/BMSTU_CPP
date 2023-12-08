#include "deletematchdialog.h"
#include "ui_deletematchdialog.h"

DeleteMatchDialog::DeleteMatchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteMatchDialog)
{
    ui->setupUi(this);
    connect(this->ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(deleteMatch()));
    connect(this->ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(close()));
}

DeleteMatchDialog::~DeleteMatchDialog()
{
    delete ui;
}

int DeleteMatchDialog::getMatchId() {
    bool matchIdValid;
    int matchId = this->ui->lineEdit->text().toInt(&matchIdValid);
    if (!matchIdValid || matchId < 0) matchId = -1;
    return matchId;
}

void DeleteMatchDialog::deleteMatch() {
    emit this->matchDeleted();
    this->ui->lineEdit->clear();
}

void DeleteMatchDialog::close() {
    this->ui->lineEdit->clear();
    QDialog::close();
}
