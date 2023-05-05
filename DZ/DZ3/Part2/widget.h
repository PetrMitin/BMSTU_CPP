#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "editor.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;
    QPushButton *CloseButton;
    QPushButton *OpenFileButton;
    Editor *editor;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void openFile();
};
#endif // WIDGET_H
