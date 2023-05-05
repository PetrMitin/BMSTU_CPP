#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("File editor");
    Widget::OpenFileButton = new QPushButton("Open file", this);
    Widget::CloseButton = new QPushButton("Exit", this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    Widget::editor = new Editor(this);
    editor->hide();
    layout->addWidget(Widget::OpenFileButton);
    layout->addWidget(Widget::CloseButton);
    connect(Widget::OpenFileButton, SIGNAL(clicked(bool)), this, SLOT(openFile()));
    connect(Widget::CloseButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::openFile() {
    QString filepath = QFileDialog::getOpenFileName(this, "Open file", "C://Users/peter/BMSTU/BMSTU_CPP", "Text files (*.txt)");
    Widget::editor->setFilepath(filepath);
    Widget::editor->show();
}
