/********************************************************************************
** Form generated from reading UI file 'editorform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORFORM_H
#define UI_EDITORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveButton;
    QPushButton *saveAsButton;
    QPushButton *closeEditorButton;

    void setupUi(QWidget *EditorForm)
    {
        if (EditorForm->objectName().isEmpty())
            EditorForm->setObjectName("EditorForm");
        EditorForm->resize(699, 564);
        verticalLayoutWidget = new QWidget(EditorForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 30, 571, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName("saveButton");

        horizontalLayout_2->addWidget(saveButton);

        saveAsButton = new QPushButton(verticalLayoutWidget);
        saveAsButton->setObjectName("saveAsButton");

        horizontalLayout_2->addWidget(saveAsButton);

        closeEditorButton = new QPushButton(verticalLayoutWidget);
        closeEditorButton->setObjectName("closeEditorButton");

        horizontalLayout_2->addWidget(closeEditorButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EditorForm);

        QMetaObject::connectSlotsByName(EditorForm);
    } // setupUi

    void retranslateUi(QWidget *EditorForm)
    {
        EditorForm->setWindowTitle(QCoreApplication::translate("EditorForm", "File editor", nullptr));
        label->setText(QCoreApplication::translate("EditorForm", "Edit your file, pozhaluista", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("EditorForm", "Times", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("EditorForm", "Helvetica [Cronyx]", nullptr));

        saveButton->setText(QCoreApplication::translate("EditorForm", "Save", nullptr));
        saveAsButton->setText(QCoreApplication::translate("EditorForm", "Save as", nullptr));
        closeEditorButton->setText(QCoreApplication::translate("EditorForm", "Close editor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditorForm: public Ui_EditorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORFORM_H
