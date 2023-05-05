#include <QFileDialog>
#include <QFontDatabase>
#include "editorform.h"
#include "ui_editorform.h"

EditorForm::EditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorForm)
{
    ui->setupUi(this);
    this->ui->comboBox->addItems(QFontDatabase().families());
    connect(this->ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeEditFont()));
    connect(this->ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(saveFile()));
    connect(this->ui->saveAsButton, SIGNAL(clicked(bool)), this, SLOT(saveFileAs()));
    connect(this->ui->closeEditorButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

EditorForm::~EditorForm()
{
    delete ui;
}

void EditorForm::show() {
    QString filepath = QFileDialog::getOpenFileName(this, "Open file", "C://Users/peter/BMSTU/BMSTU_CPP", "Text files (*.txt)");
    QFile file(filepath);
    if (filepath.length() > 0 && file.open(QFile::ReadWrite)) {
        this->filepath = filepath;
        this->ui->textEdit->setText(file.readAll());
        QWidget::show();
    }
    file.close();
}

void EditorForm::saveFile() {
    QFile file(this->filepath);
    if (this->filepath.length() > 0 && file.open(QFile::WriteOnly)) {
        QTextStream stream(&file);
        stream << this->ui->textEdit->toPlainText();
        file.flush();
        file.close();
    }
}

void EditorForm::saveFileAs() {
    QString saveFilepath = QFileDialog::getSaveFileName(this, "Save as..", "C://Users/peter/BMSTU/BMSTU_CPP", "Text files (*.txt)");
    if (saveFilepath.length() > 0) {
        QFile oldFile(this->filepath);
        oldFile.remove();
        this->filepath = saveFilepath;
        this->saveFile();
    }
}

void EditorForm::changeEditFont() {
    this->ui->textEdit->setFont(QFont(this->ui->comboBox->currentText()));
}

void EditorForm::showEvent(QShowEvent *event) {
    emit EditorForm::editorShown();
    QWidget::showEvent(event);
}

void EditorForm::closeEvent(QCloseEvent *event) {
    emit EditorForm::editorClosed();
    QWidget::closeEvent(event);
}
