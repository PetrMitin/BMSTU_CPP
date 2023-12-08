/********************************************************************************
** Form generated from reading UI file 'winsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINSDIALOG_H
#define UI_WINSDIALOG_H

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

class Ui_WinsDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *WinsDialog)
    {
        if (WinsDialog->objectName().isEmpty())
            WinsDialog->setObjectName("WinsDialog");
        WinsDialog->resize(723, 430);
        widget = new QWidget(WinsDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 50, 461, 271));
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
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WinsDialog);

        QMetaObject::connectSlotsByName(WinsDialog);
    } // setupUi

    void retranslateUi(QDialog *WinsDialog)
    {
        WinsDialog->setWindowTitle(QCoreApplication::translate("WinsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WinsDialog", "Enter number of wins", nullptr));
        cancelButton->setText(QCoreApplication::translate("WinsDialog", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WinsDialog", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinsDialog: public Ui_WinsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSDIALOG_H
