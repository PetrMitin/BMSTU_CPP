/********************************************************************************
** Form generated from reading UI file 'deleteitemdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEITEMDIALOG_H
#define UI_DELETEITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteItemDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DeleteItemDialog)
    {
        if (DeleteItemDialog->objectName().isEmpty())
            DeleteItemDialog->setObjectName("DeleteItemDialog");
        DeleteItemDialog->resize(545, 409);
        verticalLayoutWidget = new QWidget(DeleteItemDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 120, 501, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(DeleteItemDialog);

        QMetaObject::connectSlotsByName(DeleteItemDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteItemDialog)
    {
        DeleteItemDialog->setWindowTitle(QCoreApplication::translate("DeleteItemDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DeleteItemDialog", "Enter index of item to delete", nullptr));
        pushButton->setText(QCoreApplication::translate("DeleteItemDialog", "Delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeleteItemDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteItemDialog: public Ui_DeleteItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEITEMDIALOG_H
