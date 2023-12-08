/********************************************************************************
** Form generated from reading UI file 'deletematchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEMATCHDIALOG_H
#define UI_DELETEMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteMatchDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *DeleteMatchDialog)
    {
        if (DeleteMatchDialog->objectName().isEmpty())
            DeleteMatchDialog->setObjectName("DeleteMatchDialog");
        DeleteMatchDialog->resize(713, 430);
        widget = new QWidget(DeleteMatchDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(140, 100, 391, 231));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DeleteMatchDialog);

        QMetaObject::connectSlotsByName(DeleteMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteMatchDialog)
    {
        DeleteMatchDialog->setWindowTitle(QCoreApplication::translate("DeleteMatchDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DeleteMatchDialog", "Enter id of match to delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeleteMatchDialog", "Cancel", nullptr));
        pushButton->setText(QCoreApplication::translate("DeleteMatchDialog", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteMatchDialog: public Ui_DeleteMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEMATCHDIALOG_H
