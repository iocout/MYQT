#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"updatewin.h"
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QProcess>
#include<QSettings>
#include<QThread>
#include<QDir>
#include<QtConcurrent/QtConcurrent>
static const QString DOWNLOAD_FILEPATH="tmp/";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uproad=ParseIni();
    qDebug()<<"upload road: "<<uproad<<endl;
    QString update_road=uproad+"update.ini";
    c_network=new QNetworkAccessManager(this);
    request.setUrl(QUrl(update_road));
    c_reply=c_network->get(request);
    //检测版本
    connect(c_reply,&QNetworkReply::readyRead,this,&MainWindow::Showupdata);
    connect(c_reply,SIGNAL(error(QNetworkReply::NetworkError)),
            this,SLOT(OnError(QNetworkReply::NetworkError)) );

    //定时查询任务
    connect(this,SIGNAL(TimeCkVersion()) ,this,SLOT(TimeCheck()) );
}

MainWindow::~MainWindow()
{

    qDebug()<<" delete  mainwindow"<<endl;
    delete ui;
}


//确定
void MainWindow::on_btnOk_clicked()
{
    QProcess p;
    QString c = "taskkill    /F   /IM  HiramClient.exe";
    p.execute(c);
    p.close();
    Closewin();
    UpdateWin * w=new UpdateWin();
    w->setWindowFlag(Qt::Window);
    w->setDownUrl(uproad);
    w->show();
}

//取消
void MainWindow::on_btnCancel_clicked()
{
    Closewin();
}

//检测版本
void MainWindow::Showupdata()
{
    //检查tmp文件夹
    QDir dir("/tmp");
    if(!dir.exists())
    {
        QString tmpath= qApp->applicationDirPath();
        tmpath.append("/tmp");
        bool mkdir=dir.mkdir(tmpath);
        if(mkdir) qDebug()<<"make dir tmp: "<< tmpath<<endl;
    }
    QByteArray net_version=c_reply->readAll();
    QString tmp_version=DOWNLOAD_FILEPATH+"update.ini";
    QFile file(tmp_version);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        file.write(net_version);
        file.close();
    }
    QSettings settings("update.ini", QSettings::IniFormat);
    QSettings c_settings(tmp_version, QSettings::IniFormat);
    QString  version,c_version;
    if(settings.contains("Version/mainExe") && c_settings.contains("Version/mainExe"))
    {
        version= settings.value("Version/mainExe").toString();
        c_version= c_settings.value("Version/mainExe").toString();
    }
    qDebug()<<"net is: "<<c_version<<" and local is : "<<version<<endl;
    if(QString::compare(version,c_version)==0)
    {
        //版本相同
        // Closewin();
    }
    else
    {
        //显示更新信息
        QString msg_road=ParseIni()+"/updateMessage.txt";
        QNetworkRequest  msgrequest;
        msgrequest.setUrl(QUrl(msg_road));
        msgreply=c_network->get(msgrequest);
        connect(msgreply,&QNetworkReply::finished,this,[&]()
        {
            ui->MsgBox->setText(msgreply->readAll());
        });
        //此处调用show不会一闪而过
        this->show();
    }
    emit TimeCkVersion();
}

//从HiramClient.ini中解析升级路径
QByteArray MainWindow::ParseIni()
{
    QSettings settings("HiramClient.ini",QSettings::IniFormat);
    QByteArray tempArray = QByteArray::fromBase64(
                settings.value("SystemSettings/UpdateIP").toByteArray() );
    return  tempArray;
}

//错误
void MainWindow::OnError(QNetworkReply::NetworkError)
{
    if(c_reply->error())
        qDebug()<<c_reply->errorString()<<endl;
    int box = QMessageBox::critical(this,
                                    tr ("Error"),
                                    ("网络连接错误，请检查你的网络设置!"),
                                    QMessageBox::Close);
    if(box==QMessageBox::Close)
    {
        Closewin();
        exit(EXIT_FAILURE);
    }
}

//关闭主界面
void MainWindow::Closewin()
{
    this->close();
}

void MainWindow::TimeCheck()//定时检查任务
{
    //使用一个多线程去定时查询版本是否一致
    //    QtConcurrent::run([&](){
    //        QThread::sleep(3);
    //        c_reply=c_network->get(request);
    //        connect(c_reply,&QNetworkReply::readyRead,this,&MainWindow::Showupdata);
    //        connect(c_reply,SIGNAL(error(QNetworkReply::NetworkError)),
    //                this,SLOT(OnError(QNetworkReply::NetworkError)) );
    //        qDebug()<<"check the virsion in 3 Sec!"<<endl;
    //    });
    QMutex mutex;
    QTimer * timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[&](){
        c_reply=c_network->get(request);
        connect(c_reply,&QNetworkReply::readyRead,this,&MainWindow::Showupdata);
        connect(c_reply,SIGNAL(error(QNetworkReply::NetworkError)),
                this,SLOT(OnError(QNetworkReply::NetworkError)) );
        qDebug()<<"check the virsion in 3 Sec!"<<endl;
    });
    timer->start(5000);
}
