/********************************************************************************
** Form generated from reading UI file 'protobuf_3_0.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOBUF_3_0_H
#define UI_PROTOBUF_3_0_H

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

class Ui_protobuf_3_0Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *protobuf_3_0Class)
    {
        if (protobuf_3_0Class->objectName().isEmpty())
            protobuf_3_0Class->setObjectName(QStringLiteral("protobuf_3_0Class"));
        protobuf_3_0Class->resize(600, 400);
        menuBar = new QMenuBar(protobuf_3_0Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        protobuf_3_0Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(protobuf_3_0Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        protobuf_3_0Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(protobuf_3_0Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        protobuf_3_0Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(protobuf_3_0Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        protobuf_3_0Class->setStatusBar(statusBar);

        retranslateUi(protobuf_3_0Class);

        QMetaObject::connectSlotsByName(protobuf_3_0Class);
    } // setupUi

    void retranslateUi(QMainWindow *protobuf_3_0Class)
    {
        protobuf_3_0Class->setWindowTitle(QApplication::translate("protobuf_3_0Class", "protobuf_3_0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class protobuf_3_0Class: public Ui_protobuf_3_0Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOBUF_3_0_H
