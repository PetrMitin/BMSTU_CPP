#include "widgetform.h"
#include "ui_widgetform.h"

widgetForm::widgetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetForm)
{
    ui->setupUi(this);
}

widgetForm::~widgetForm()
{
    delete ui;
}
