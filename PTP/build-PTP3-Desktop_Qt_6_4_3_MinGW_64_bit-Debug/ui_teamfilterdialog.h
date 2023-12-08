/********************************************************************************
** Form generated from reading UI file 'teamfilterdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMFILTERDIALOG_H
#define UI_TEAMFILTERDIALOG_H

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

class Ui_TeamFilterDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *filterButton;

    void setupUi(QDialog *TeamFilterDialog)
    {
        if (TeamFilterDialog->objectName().isEmpty())
            TeamFilterDialog->setObjectName("TeamFilterDialog");
        TeamFilterDialog->resize(646, 482);
        widget = new QWidget(TeamFilterDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 100, 431, 261));
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

        filterButton = new QPushButton(widget);
        filterButton->setObjectName("filterButton");

        horizontalLayout->addWidget(filterButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TeamFilterDialog);

        QMetaObject::connectSlotsByName(TeamFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *TeamFilterDialog)
    {
        TeamFilterDialog->setWindowTitle(QCoreApplication::translate("TeamFilterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TeamFilterDialog", "Enter team name", nullptr));
        cancelButton->setText(QCoreApplication::translate("TeamFilterDialog", "Cancel", nullptr));
        filterButton->setText(QCoreApplication::translate("TeamFilterDialog", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeamFilterDialog: public Ui_TeamFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMFILTERDIALOG_H
