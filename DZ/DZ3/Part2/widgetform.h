#ifndef WIDGETFORM_H
#define WIDGETFORM_H

#include <QWidget>

namespace Ui {
class widgetForm;
}

class widgetForm : public QWidget
{
    Q_OBJECT

public:
    explicit widgetForm(QWidget *parent = nullptr);
    ~widgetForm();

private:
    Ui::widgetForm *ui;
};

#endif // WIDGETFORM_H
