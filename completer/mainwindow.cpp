#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QComboBox>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("sku");
    // db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");

    if(!db.open())
    {
        QSqlError error=db.lastError();
        qDebug()<<"error:"<<error;
        exit(EXIT_FAILURE);
    }
    QSqlQueryModel * model=new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM ar_user");
    ui->tableView->setModel(model);
    QCompleter * completer=new QCompleter(model,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionColumn(2);
    completer->setFilterMode(Qt::MatchContains);  //设置模糊匹配模式
    ui->lineEdit->setCompleter(completer);
    qDebug()<<completer->currentCompletion();
}
