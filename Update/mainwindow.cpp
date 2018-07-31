#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"updatewin.h"
#include"method.h"
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QProcess>
#include<QSettings>
#include<QThread>
#include<QTimer>
#include<QDir>
#include<QSharedMemory>
#include<QLocalSocket>
#include<QtConcurrent/QtConcurrent>

QTimer * timer;
static const QString DOWNLOAD_FILEPATH="tmp/";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    firstopen(true),
    isRuning(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initnetwork();
    TimeCkversion();
}

MainWindow::~MainWindow()
{
    qDebug()<<" delete  mainwindow"<<endl;
    delete ui;
}

//初始化
void MainWindow::Initnetwork()
{
    initLocalConnection();
    if(isRuning)
    {
        qDebug()<<"is runing "<<endl;
        exit(EXIT_SUCCESS);
    }
    uproad=ParseIni();
    qDebug()<<"upload road: "<<uproad<<endl;
    QString update_road=uproad+"update.ini";
    c_network=new QNetworkAccessManager(this);
    c_request.setUrl(QUrl(update_road));
    c_reply=c_network->get(c_request);
    //    检测版本
    connect(c_reply,&QNetworkReply::readyRead,this,&MainWindow::Showupdata);
    connect(c_reply,SIGNAL(error(QNetworkReply::NetworkError)),
            this,SLOT(OnError(QNetworkReply::NetworkError)) );
}

//确定
void MainWindow::on_btnOk_clicked()
{
    QProcess p;
    QString c = "taskkill    /F   /IM  HiramClient.exe";//终止所有该名字的进程
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
    //取消更新后，除非重启软件，否则不会检查更新
    this->close();
}

//检测版本
void MainWindow::Showupdata()
{
    //检查tmp文件夹
    QDir dir("tmp");
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
    if(QString::compare(version,c_version)!=0)
    {
        //显示更新信息
        QString msg_road=ParseIni()+"/updateMessage.txt";
        QNetworkRequest  msgc_request;
        msgc_request.setUrl(QUrl(msg_road));
        msgreply=c_network->get(msgc_request);
        connect(msgreply,&QNetworkReply::finished,this,[&]()
        {
            ui->MsgBox->setText(msgreply->readAll());
        });
        //此处调用show不会一闪而过  一直最前
        this->hide();
        setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
        this->showNormal();
        //定时器停止信号
        emit TimeCkVersion();
    }
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
    QMessageBox msgBox;
    msgBox.setWindowTitle("错误");
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("网络连接错误，请检查你的网络设置");
    msgBox.exec();
    this->close();
    exit(EXIT_FAILURE);
}

//关闭主界面
void MainWindow::Closewin()
{
    this->hide();
}

//定时检查版本
void MainWindow::TimeCkversion()
{
    //更新完成，继续检查
    timer=new QTimer(this);
    timer->start(10000);
    connect(timer,&QTimer::timeout,this,[&](){
        c_reply=c_network->get(c_request);
        connect(c_reply,&QNetworkReply::readyRead,this,&MainWindow::Showupdata);
        qDebug()<<"qtimer is done"<<endl;
    });
    //正在更新，停止检查
    connect(this,&MainWindow::TimeCkVersion,[&](){
        timer->stop();
        qDebug()<<"stop the timer"<<endl;
    });
}


void MainWindow::initLocalConnection()
{
//    //1.先检测是否已经打开了一个例程
//     QSharedMemory memory;
//    //创建基于平台键值，win会在没有进程使用共享内存时销毁该memory,以此来判断是否已经运行了一个该例程
//    memory.setKey(QString("HiramClientUpdateService"));
//    if(!memory.create(1))
//    {
//        qDebug()<<"instance has establish!"<<endl;
//        isRuning=true;
//        exit(EXIT_SUCCESS);
//    }

    //2.连接LocalServer
    QCoreApplication::setApplicationName("localserver");
    QString serverName = QCoreApplication::applicationName();
    QLocalSocket socket;
    socket.connectToServer(serverName);
    if(socket.waitForConnected(500))
    {
        isRuning =true;
        return;
    }

    //连接不上服务器，就创建一个
    server =new QLocalServer(this);
    connect(server, SIGNAL(newConnection()), this,SLOT(newLocalConnection()));
    if(server->listen(serverName))
    {
        //防止程序崩溃时,残留进程服务,移除之
        if(server->serverError()== QAbstractSocket::AddressInUseError &&QFile::exists(server->serverName()))
        {
            QFile::remove(server->serverName());
            server->listen(serverName);
        }
    }
}


void MainWindow::newLocalConnection()
{
    QLocalSocket *socket =server->nextPendingConnection();
    if(!socket)
        return;
    socket->waitForReadyRead(1000);
    delete socket;
}
