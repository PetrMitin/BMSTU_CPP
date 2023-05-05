#ifndef DIALOGEX2_H
#define DIALOGEX2_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DialogEx2; }
QT_END_NAMESPACE

class DialogEx2 : public QDialog
{
    Q_OBJECT

public:
    DialogEx2(QWidget *parent = nullptr);
    ~DialogEx2();

private:
    Ui::DialogEx2 *ui;

private slots:
    void onExitClicked();
};
#endif // DIALOGEX2_H
