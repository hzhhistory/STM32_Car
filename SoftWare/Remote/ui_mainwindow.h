/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *up;
    QPushButton *left;
    QPushButton *off;
    QPushButton *right;
    QPushButton *down;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        up = new QPushButton(centralWidget);
        up->setObjectName(QStringLiteral("up"));

        gridLayout->addWidget(up, 0, 1, 1, 1);

        left = new QPushButton(centralWidget);
        left->setObjectName(QStringLiteral("left"));

        gridLayout->addWidget(left, 1, 0, 1, 1);

        off = new QPushButton(centralWidget);
        off->setObjectName(QStringLiteral("off"));

        gridLayout->addWidget(off, 1, 1, 1, 1);

        right = new QPushButton(centralWidget);
        right->setObjectName(QStringLiteral("right"));

        gridLayout->addWidget(right, 1, 2, 1, 1);

        down = new QPushButton(centralWidget);
        down->setObjectName(QStringLiteral("down"));

        gridLayout->addWidget(down, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\201\245\346\216\247\344\270\212\344\275\215\346\234\272", 0));
        up->setText(QApplication::translate("MainWindow", "\344\270\212", 0));
        left->setText(QApplication::translate("MainWindow", "\345\267\246", 0));
        off->setText(QApplication::translate("MainWindow", "\345\205\263", 0));
        right->setText(QApplication::translate("MainWindow", "\345\217\263", 0));
        down->setText(QApplication::translate("MainWindow", "\344\270\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
