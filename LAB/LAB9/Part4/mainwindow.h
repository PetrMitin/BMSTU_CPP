#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void setInputText();

    void convert();

private:
    QLineEdit *inputEdit;

    QPlainTextEdit *outputEdit;

    bool isUppercase = true;

};
#endif // MAINWINDOW_H
