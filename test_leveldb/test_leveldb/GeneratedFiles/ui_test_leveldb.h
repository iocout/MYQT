/********************************************************************************
** Form generated from reading UI file 'test_leveldb.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_LEVELDB_H
#define UI_TEST_LEVELDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_leveldbClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test_leveldbClass)
    {
        if (test_leveldbClass->objectName().isEmpty())
            test_leveldbClass->setObjectName(QStringLiteral("test_leveldbClass"));
        test_leveldbClass->resize(600, 400);
        menuBar = new QMenuBar(test_leveldbClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        test_leveldbClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test_leveldbClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        test_leveldbClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(test_leveldbClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        test_leveldbClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(test_leveldbClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        test_leveldbClass->setStatusBar(statusBar);

        retranslateUi(test_leveldbClass);

        QMetaObject::connectSlotsByName(test_leveldbClass);
    } // setupUi

    void retranslateUi(QMainWindow *test_leveldbClass)
    {
        test_leveldbClass->setWindowTitle(QApplication::translate("test_leveldbClass", "test_leveldb", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class test_leveldbClass: public Ui_test_leveldbClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_LEVELDB_H
