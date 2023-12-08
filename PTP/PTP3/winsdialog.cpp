#include "winsdialog.h"
#include "ui_winsdialog.h"

WinsDialog::WinsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinsDialog)
{
    ui->setupUi(this);
    connect(this->ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(enterWins()));
    connect(this->ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

WinsDialog::~WinsDialog()
{
    delete ui;
}

void WinsDialog::close() {
    this->ui->lineEdit->clear();
    QDialog::close();
}

void WinsDialog::enterWins() {
    emit this->winsEntered();
    this->ui->lineEdit->clear();
}

int WinsDialog::getWins() {
    bool ok;
    int wins = this->ui->lineEdit->text().toInt(&ok);
    if (!ok) wins = -1;
    return wins;
}
