/********************************************************************************
** Form generated from reading UI file 'additemdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMDIALOG_H
#define UI_ADDITEMDIALOG_H

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

class Ui_addItemDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *priceEdit;
    QLabel *label_3;
    QLineEdit *amountEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *addItemDialog)
    {
        if (addItemDialog->objectName().isEmpty())
            addItemDialog->setObjectName("addItemDialog");
        addItemDialog->resize(400, 349);
        verticalLayoutWidget = new QWidget(addItemDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 50, 351, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(verticalLayoutWidget);
        nameEdit->setObjectName("nameEdit");

        verticalLayout->addWidget(nameEdit);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        priceEdit = new QLineEdit(verticalLayoutWidget);
        priceEdit->setObjectName("priceEdit");

        verticalLayout->addWidget(priceEdit);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        amountEdit = new QLineEdit(verticalLayoutWidget);
        amountEdit->setObjectName("amountEdit");

        verticalLayout->addWidget(amountEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        submitButton = new QPushButton(verticalLayoutWidget);
        submitButton->setObjectName("submitButton");

        horizontalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(addItemDialog);

        QMetaObject::connectSlotsByName(addItemDialog);
    } // setupUi

    void retranslateUi(QDialog *addItemDialog)
    {
        addItemDialog->setWindowTitle(QCoreApplication::translate("addItemDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addItemDialog", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("addItemDialog", "Price", nullptr));
        label_3->setText(QCoreApplication::translate("addItemDialog", "Amount", nullptr));
        submitButton->setText(QCoreApplication::translate("addItemDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("addItemDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addItemDialog: public Ui_addItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMDIALOG_H
