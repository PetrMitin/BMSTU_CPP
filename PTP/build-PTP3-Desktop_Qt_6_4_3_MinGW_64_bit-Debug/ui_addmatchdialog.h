/********************************************************************************
** Form generated from reading UI file 'addmatchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMATCHDIALOG_H
#define UI_ADDMATCHDIALOG_H

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

class Ui_AddMatchDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *stadiumEdit;
    QLabel *label_3;
    QLineEdit *team1Edit;
    QLabel *label_4;
    QLineEdit *team2Edit;
    QLabel *label_5;
    QLineEdit *team1ScoreEdit;
    QLabel *label_2;
    QLineEdit *team2ScoreEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *submitButton;

    void setupUi(QDialog *AddMatchDialog)
    {
        if (AddMatchDialog->objectName().isEmpty())
            AddMatchDialog->setObjectName("AddMatchDialog");
        AddMatchDialog->resize(792, 446);
        widget = new QWidget(AddMatchDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 10, 711, 411));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        stadiumEdit = new QLineEdit(widget);
        stadiumEdit->setObjectName("stadiumEdit");

        verticalLayout->addWidget(stadiumEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        team1Edit = new QLineEdit(widget);
        team1Edit->setObjectName("team1Edit");

        verticalLayout->addWidget(team1Edit);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        team2Edit = new QLineEdit(widget);
        team2Edit->setObjectName("team2Edit");

        verticalLayout->addWidget(team2Edit);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        team1ScoreEdit = new QLineEdit(widget);
        team1ScoreEdit->setObjectName("team1ScoreEdit");

        verticalLayout->addWidget(team1ScoreEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        team2ScoreEdit = new QLineEdit(widget);
        team2ScoreEdit->setObjectName("team2ScoreEdit");

        verticalLayout->addWidget(team2ScoreEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        submitButton = new QPushButton(widget);
        submitButton->setObjectName("submitButton");

        horizontalLayout->addWidget(submitButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(AddMatchDialog);

        QMetaObject::connectSlotsByName(AddMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *AddMatchDialog)
    {
        AddMatchDialog->setWindowTitle(QCoreApplication::translate("AddMatchDialog", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("AddMatchDialog", "Add New Match, pozhaluista", nullptr));
        label->setText(QCoreApplication::translate("AddMatchDialog", "Stadium", nullptr));
        label_3->setText(QCoreApplication::translate("AddMatchDialog", "Team 1", nullptr));
        label_4->setText(QCoreApplication::translate("AddMatchDialog", "Team 2", nullptr));
        label_5->setText(QCoreApplication::translate("AddMatchDialog", "Team 1 Score", nullptr));
        label_2->setText(QCoreApplication::translate("AddMatchDialog", "Team 2 Score", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddMatchDialog", "Cancel", nullptr));
        submitButton->setText(QCoreApplication::translate("AddMatchDialog", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMatchDialog: public Ui_AddMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMATCHDIALOG_H
