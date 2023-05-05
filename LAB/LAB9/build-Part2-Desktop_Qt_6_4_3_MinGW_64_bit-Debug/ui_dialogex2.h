/********************************************************************************
** Form generated from reading UI file 'dialogex2.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEX2_H
#define UI_DIALOGEX2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEx2
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout;
    QDial *dial;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *btnExit;

    void setupUi(QDialog *DialogEx2)
    {
        if (DialogEx2->objectName().isEmpty())
            DialogEx2->setObjectName("DialogEx2");
        DialogEx2->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(DialogEx2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        textEdit = new QTextEdit(DialogEx2);
        textEdit->setObjectName("textEdit");

        horizontalLayout_2->addWidget(textEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        dial = new QDial(DialogEx2);
        dial->setObjectName("dial");

        verticalLayout->addWidget(dial);

        spinBox = new QSpinBox(DialogEx2);
        spinBox->setObjectName("spinBox");

        verticalLayout->addWidget(spinBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DialogEx2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        btnExit = new QPushButton(DialogEx2);
        btnExit->setObjectName("btnExit");

        horizontalLayout->addWidget(btnExit);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DialogEx2);
        QObject::connect(dial, &QDial::sliderMoved, spinBox, &QSpinBox::setValue);
        QObject::connect(spinBox, &QSpinBox::valueChanged, dial, &QDial::setValue);
        QObject::connect(btnExit, &QPushButton::clicked, DialogEx2, qOverload<>(&QDialog::reject));
        QObject::connect(spinBox, &QSpinBox::textChanged, textEdit, &QTextEdit::append);

        QMetaObject::connectSlotsByName(DialogEx2);
    } // setupUi

    void retranslateUi(QDialog *DialogEx2)
    {
        DialogEx2->setWindowTitle(QCoreApplication::translate("DialogEx2", "DialogEx2", nullptr));
        label->setText(QCoreApplication::translate("DialogEx2", "\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203 ->", nullptr));
        btnExit->setText(QCoreApplication::translate("DialogEx2", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEx2: public Ui_DialogEx2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEX2_H
