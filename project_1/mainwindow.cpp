#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QModelIndex>
#include <QtNetwork/QtNetwork>
#include <QtSql/qsql.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QVector>
#include <QVariant>
#include <QString>
#include <QScopedPointer>
#include <QMessageBox>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    status=false;//打开单据时不可编辑
    model=new QStandardItemModel(this);
    backup_model=new QStandardItemModel(this);
    pageflag=new code();
    pageflag->codes="";
    pageflag->isCheck=false;

    initStyle();
    initheader();
    vector();
    getdata();
    ui->main_tab->setModel(model);
    ui->main_tab->installEventFilter(this);//监听事件

    //右键支持
    ui->main_tab->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->main_tab,&QTableView::customContextMenuRequested,
            this,&MainWindow::onListContextMenu);
    //菜单
}
MainWindow::~MainWindow()
{
    delete pageflag;
    pageflag=nullptr;
    delete ui;
}

//初始化样式
void MainWindow::initStyle()
{
    //加载样式表
    QFile file(":/css/flatwhite.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QString(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
    this->setWindowState(Qt::WindowMaximized);//设置全屏
}

//获取表头信息
void MainWindow::getdata()
{
    int i=0;
    QSqlQuery query;
    query.exec("SELECT * from ic_general_body");
    while(query.next()){
        for(int j=0;j<7;j++){
            model->setItem(i,j,new QStandardItem(query.value(j).toString()));
//            backup_model->setItem(i,j,new QStandardItem(query.value(j).toString()));
        }
        i++;
    }
    qDebug()<<"back_model"<<backup_model<<endl;
}

//定义表头
void MainWindow::vector()
{
    model->setHorizontalHeaderLabels(QStringList()<<"ic_general_body_id"<<"ic_general_head_id"<<QStringLiteral("条码号")
                                     <<QStringLiteral("科目字典-销售方式")<<QStringLiteral("科目字典-级别")<<QStringLiteral("科目字典-款号")
                                     <<QStringLiteral("科目字典-材料")<<QStringLiteral("科目字典-品名")<< QStringLiteral("标签名")
                                     );
}

//初始化表头，定义表头大小等
void MainWindow::initheader()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sku");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()){
        qDebug()<<" Database error :"<<db.lastError();
    }
    QSqlQuery query;
    //先查到打开时的单号,审核状态等


    ui->main_tab->horizontalHeader()->setSectionsMovable(true);
    ui->main_tab->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->main_tab->setAlternatingRowColors(true);
    ui->main_tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->main_tab->setSelectionBehavior(QAbstractItemView::SelectRows);//选中行
    //    ui->main_tab->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection); // 只能单选
    ischeckenableBtn(pageflag->isCheck=false);
}

//设置未审核单据按钮状态位
void MainWindow::ischeckenableBtn(bool status)
{
    if(status){
        ui->btn_edit->setEnabled(false);
        ui->btn_del->setEnabled(false);
        ui->btn_check->setEnabled(false);
        ui->btn_save->setEnabled(false);
        ui->btn_cancel->setEnabled(false);
        ui->btn_add->setEnabled(true);
    }else{
        ui->btn_add->setEnabled(true);
        ui->btn_check->setEnabled(true);
        ui->btn_del->setEnabled(true);
        ui->btn_edit->setEnabled(true);
        ui->btn_cancel->setEnabled(false);
        ui->btn_save->setEnabled(false);
    }
}

//添加
void MainWindow::on_btn_add_clicked()
{
    ui->main_tab->setModel(nullptr);
    model->removeRows(0,model->rowCount());//清空表体
    model->appendRow(new QStandardItem());
    ui->main_tab->setEditTriggers(QAbstractItemView::AllEditTriggers);//可编辑
    ui->main_tab->setModel(model);
    ischeckenableBtn(true);
    ui->btn_add->setEnabled(false);
    ui->btn_save->setEnabled(true);
    ui->btn_cancel->setEnabled(true);
}

//编辑
void MainWindow::on_btn_edit_clicked()
{
    ui->btn_edit->setEnabled(false);
    ui->btn_del->setEnabled(false);
    ui->btn_check->setEnabled(false);
    ui->btn_save->setEnabled(true);
    ui->btn_cancel->setEnabled(true);
    ui->btn_add->setEnabled(false);
    ui->main_tab->setEditTriggers(QAbstractItemView::AllEditTriggers);//可编辑
}

//删除
void MainWindow::on_btn_del_clicked()
{
    model->clear();
    QSqlQuery query;
    query.prepare(QString("DELETE FROM ic_general_body WHERE ic_general_body_id = %1").
                  arg(pageflag->codes));
    query.exec();
    vector();
}

//保存
void MainWindow::on_btn_save_clicked()
{

}

//审核
void MainWindow::on_btn_check_clicked()
{

}

//入库单号复制
void MainWindow::on_btn_copy_clicked()
{

}
//批设
void MainWindow::on_pushButton_5_clicked()
{

}

//取消
void MainWindow::on_btn_cancel_clicked()
{
    ischeckenableBtn(pageflag->isCheck);
    ui->main_tab->setEditTriggers(QAbstractItemView::AllEditTriggers);//不可编辑
    ui->main_tab->setModel(backup_model);
}

//导出excel
void MainWindow::on_btn_excel_clicked()
{

}

//添加右键菜单
void MainWindow::onListContextMenu(const QPoint &pt)
{
    QMenu menu;
    menu.addAction(ui->actionadd);
    menu.addAction(ui->actionrow);
    menu.exec(ui->main_tab->mapToGlobal(pt));
}

//打印
void MainWindow::on_btn_print_clicked()
{

}

//右键添加
void MainWindow::on_actionadd_triggered()
{
    QStandardItem * item=new QStandardItem();
    ui->main_tab->scrollToBottom();
    ui->main_tab->setFocus();
    model->appendRow(item);
    QModelIndex index=model->index(model->rowCount(),0);
    ui->main_tab->setCurrentIndex(index);
    ui->main_tab->edit(index);
}

//删除选中行
void MainWindow::on_actionrow_triggered()
{
    QScopedPointer<QItemSelectionModel> selectionmodel(ui->main_tab->selectionModel());
    if(selectionmodel->hasSelection()){
        for(auto i:selectionmodel->selectedRows())
        {
            model->removeRow(i.row());
            qDebug()<<"i"<<i.row()<<endl;
        }
        return;
    }
    else{
//    QMessageBox box
    }
}
