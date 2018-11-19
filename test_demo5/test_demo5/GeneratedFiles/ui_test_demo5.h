/********************************************************************************
** Form generated from reading UI file 'test_demo5.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_DEMO5_H
#define UI_TEST_DEMO5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_demo5Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test_demo5Class)
    {
        if (test_demo5Class->objectName().isEmpty())
            test_demo5Class->setObjectName(QStringLiteral("test_demo5Class"));
        test_demo5Class->resize(600, 400);
        centralWidget = new QWidget(test_demo5Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        test_demo5Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(test_demo5Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        test_demo5Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test_demo5Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        test_demo5Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(test_demo5Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        test_demo5Class->setStatusBar(statusBar);

        retranslateUi(test_demo5Class);

        QMetaObject::connectSlotsByName(test_demo5Class);
    } // setupUi

    void retranslateUi(QMainWindow *test_demo5Class)
    {
        test_demo5Class->setWindowTitle(QApplication::translate("test_demo5Class", "test_demo5", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class test_demo5Class: public Ui_test_demo5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_DEMO5_H
