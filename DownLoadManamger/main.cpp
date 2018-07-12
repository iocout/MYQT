#include "downloadmanager.h"
#include "checkversion.h"
#include <QApplication>
#include<QTextCodec>
#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    checkVersion w;
    return a.exec();
}
