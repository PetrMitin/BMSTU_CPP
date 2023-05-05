#include "editor.h"
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>

Editor::Editor(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(0, 0, parent->width(), parent->height());
    Editor::filepath = "";
    Editor::edit = new QTextEdit(this);
    Editor::label = new QLabel("Edit your file, pozhaluista", this);
    Editor::saveButton = new QPushButton("Save", this);
    Editor::saveAsButton = new QPushButton("Save as", this);
    Editor::closeButton = new QPushButton("Close", this);
    Editor::fontSelectDropdown = new QComboBox(this);
    Editor::fontSelectDropdown->addItem("Times New Roman");
    Editor::fontSelectDropdown->addItem("Calibri");

    Editor::titleLayout = new QHBoxLayout(this);
    Editor::titleLayout->addWidget(Editor::label);
    Editor::titleLayout->addWidget(Editor::fontSelectDropdown);
    titleLayout->setGeometry(QRect(0, 0, this->width(), this->height()*0.1));

    Editor::editLayout = new QVBoxLayout(this);
    Editor::editLayout->addLayout(titleLayout);
    Editor::editLayout->addWidget(Editor::edit);
    editLayout->setGeometry(QRect(0, this->height()*0.1, this->width(), this->height()*0.8));

    Editor::controlsLayout = new QHBoxLayout(this);
    Editor::controlsLayout->addWidget(saveButton);
    Editor::controlsLayout->addWidget(saveAsButton);
    Editor::controlsLayout->addWidget(closeButton);
    controlsLayout->setGeometry(QRect(0, this->height()*0.8, this->width(), this->height()*0.1));

    QFrame *editorFrame = new QFrame(this);
    editorFrame->setGeometry(QRect(0, 0, this->width(), this->height()));
    Editor::editorUi = new QVBoxLayout(this);
    Editor::editorUi->addLayout(editLayout);
    Editor::editorUi->addLayout(controlsLayout);
    this->editorUi->addWidget(editorFrame);

    connect(Editor::closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Editor::setFilepath(QString filepath) {
    Editor::filepath = filepath;
}

void Editor::showEvent(QShowEvent *event) {
    if (Editor::filepath.length() > 0) {
        QFile file(Editor::filepath);
        file.open(QFile::ReadWrite);
        Editor::edit->setText(file.readAll());
    }
    QWidget::showEvent(event);
}

void Editor::closeEvent(QCloseEvent *event) {
    ((QWidget*)this->parent())->show();
    QWidget::closeEvent(event);
}
