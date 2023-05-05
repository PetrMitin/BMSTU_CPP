#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Editor : public QWidget
{
    Q_OBJECT

private:
    QString filepath;
    QTextEdit *edit;
    QLabel *label;
    QPushButton *saveButton;
    QPushButton *saveAsButton;
    QPushButton *closeButton;
    QComboBox *fontSelectDropdown;
    QHBoxLayout *titleLayout;
    QVBoxLayout *editLayout;
    QHBoxLayout *controlsLayout;
    QVBoxLayout *editorUi;

public:
    explicit Editor(QWidget *parent = nullptr);

    void showEvent(QShowEvent* event) override;

    void closeEvent(QCloseEvent *event) override;

    void setFilepath(QString filepath);
};

#endif // EDITOR_H
