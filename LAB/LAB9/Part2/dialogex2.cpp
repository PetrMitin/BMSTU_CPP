#include "dialogex2.h"
#include "ui_dialogex2.h"
#include <QMessageBox>

DialogEx2::DialogEx2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogEx2)
{
    ui->setupUi(this);
    connect(ui->btnExit, SIGNAL(clicked()), this, SLOT(onExitClicked()));
}

DialogEx2::~DialogEx2()
{
    delete ui;
}

void DialogEx2::onExitClicked()
{
    // Спрашиваем, закрывать приложение или нет
    if( QMessageBox::question ( this, QString(),
    "Завершить приложение?", QMessageBox::Yes|QMessageBox::No) ==
    QMessageBox::Yes ) exit(0);
    else show();
}
