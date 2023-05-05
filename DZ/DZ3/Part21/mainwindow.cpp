#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->editor = new EditorForm(this);
    this->editor->hide();
    connect(this->ui->openFileButton, SIGNAL(clicked(bool)), this->editor, SLOT(show()));
    connect(this->editor, SIGNAL(editorShown()), this->ui->mainControlsWidget, SLOT(hide()));
    connect(this->editor, SIGNAL(editorClosed()), this->ui->mainControlsWidget, SLOT(show()));
    connect(this->ui->closeAppButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete editor;
}

