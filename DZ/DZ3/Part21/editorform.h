#ifndef EDITORFORM_H
#define EDITORFORM_H

#include <QWidget>

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent = nullptr);
    ~EditorForm();

    void showEvent(QShowEvent *event) override;

    void closeEvent(QCloseEvent *event) override;
private:
    Ui::EditorForm *ui;
    QString filepath;

signals:
    void editorShown();

    void editorClosed();

public slots:
    void saveFile();

    void saveFileAs();

    void changeEditFont();

    void show();
};

#endif // EDITORFORM_H
