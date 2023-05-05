#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->inputEdit = new QLineEdit(this);
    QPushButton *convertButton = new QPushButton(this);
    convertButton->setText("Convert");
    this->outputEdit = new QPlainTextEdit(this);
    outputEdit->setReadOnly(true);
    layout->addWidget(inputEdit);
    layout->addWidget(convertButton);
    layout->addWidget(outputEdit);
    layout->setGeometry(QRect(0, 0, 1000, 1000));

    connect(this->inputEdit, SIGNAL(editingFinished()), this, SLOT(setInputText()));
    connect(convertButton, SIGNAL(clicked(bool)), this, SLOT(convert()));
}

void MainWindow::setInputText() {
    QString input = this->inputEdit->text();
    this->outputEdit->clear();
    this->outputEdit->appendPlainText("input: " + input + '\n');
}

void MainWindow::convert() {
    QString input = this->inputEdit->text();
    this->isUppercase
        ? this->outputEdit->appendPlainText("ALL UPPERCASE: " + input.toUpper())
        : this->outputEdit->appendPlainText("all lowercase: " + input.toLower());
    this->isUppercase = !this->isUppercase;
}

MainWindow::~MainWindow()
{
    QWidget::~QWidget();
}

