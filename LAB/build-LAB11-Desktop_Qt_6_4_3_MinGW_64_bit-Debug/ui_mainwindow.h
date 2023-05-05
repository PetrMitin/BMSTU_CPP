/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *surfaceWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *selectMarkOptions;
    QPushButton *saveMarkButton;
    QPushButton *deleteMarkButton;
    QSpacerItem *verticalSpacer;
    QPushButton *closeAppButton;
    QMenuBar *menubar;
    QMenu *menuLAB_11;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1104, 689);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        surfaceWidget = new QWidget(centralwidget);
        surfaceWidget->setObjectName("surfaceWidget");
        surfaceWidget->setGeometry(QRect(20, 50, 651, 531));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(710, 60, 371, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        selectMarkOptions = new QComboBox(verticalLayoutWidget);
        selectMarkOptions->setObjectName("selectMarkOptions");

        verticalLayout->addWidget(selectMarkOptions);

        saveMarkButton = new QPushButton(verticalLayoutWidget);
        saveMarkButton->setObjectName("saveMarkButton");

        verticalLayout->addWidget(saveMarkButton);

        deleteMarkButton = new QPushButton(verticalLayoutWidget);
        deleteMarkButton->setObjectName("deleteMarkButton");

        verticalLayout->addWidget(deleteMarkButton);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        closeAppButton = new QPushButton(verticalLayoutWidget);
        closeAppButton->setObjectName("closeAppButton");

        verticalLayout->addWidget(closeAppButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1104, 25));
        menuLAB_11 = new QMenu(menubar);
        menuLAB_11->setObjectName("menuLAB_11");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLAB_11->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select existing mark", nullptr));
        saveMarkButton->setText(QCoreApplication::translate("MainWindow", "Save current mark", nullptr));
        deleteMarkButton->setText(QCoreApplication::translate("MainWindow", "Delete existing mark", nullptr));
        closeAppButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        menuLAB_11->setTitle(QCoreApplication::translate("MainWindow", "LAB 11", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
