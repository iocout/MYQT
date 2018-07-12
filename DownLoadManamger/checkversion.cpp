#include "checkversion.h"
#include "downloadmanager.h"
#include "ui_checkversion.h"
#include<QByteArray>
#include<QFile>
#include<QSettings>
#include<QMessageBox>
#include<QProcess>

static const QString DOWNLOAD_FILE_SUFFIX = "_tmp";
QString exeurl;

checkVersion::checkVersion(QWidget *parent) :
    QWidget(parent),
    v_network(NULL),
    ui(new Ui::checkVersion)
{
    ui->setupUi(this);
    //中文路径问题
    QSettings settings("HiramClient.ini", QSettings::IniFormat);
    QByteArray tempArray = QByteArray::fromBase64(settings.value("SystemSettings/UpdateIP").toByteArray() );
    QString value(tempArray+"update.ini");
    url=value;
    value=tempArray+"updateMessage.txt";
    mesUrl=value;
    value=tempArray+"HiramClient.exe";
    exeurl=value;

    v_network= new QNetworkAccessManager(this);

    //查询版本信息
    QNetworkRequest v_request;
    v_request.setUrl(QUrl(url));
    v_reply =v_network->get(v_request);
    connect(v_reply, SIGNAL(readyRead()), this , SLOT(isversion()) );
    connect(v_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this ,SLOT(OnError(QNetworkReply::NetworkError)) );
    //查询更新日志
    QNetworkRequest mes_request;
    mes_request.setUrl(mesUrl);
    mes_reply=v_network->get(mes_request);
    connect(mes_reply, SIGNAL(finished()), this , SLOT(MessageShow()) );
    connect(mes_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this ,SLOT(OnError(QNetworkReply::NetworkError)) );
}

checkVersion::~checkVersion()
{
    delete ui;
}

//版本检测
void checkVersion::isversion()
{
    QByteArray data=v_reply->readAll();
    QString v_version;
    v_version.append("v");
    int ind=data.indexOf("mainExe")+9;
    for(int i=ind;i<ind+9;i++)
        if((data.at(i)=='.') || isdigit(data.at(i)))
            v_version.append(data.at(i));
        else
            break;
    QString tmp_version= qApp->applicationDirPath();
    tmp_version="tmp\\update.ini"+DOWNLOAD_FILE_SUFFIX;
    QFile file(tmp_version);
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
    }
    QSettings settings("update.ini", QSettings::IniFormat);
    QString  version;
    if(settings.contains("Version/mainExe"))
    {
        version= settings.value("Version/mainExe").toString();
    }
    if(version==v_version)
    {     
        file.close();
        this->setAttribute(Qt::WA_DeleteOnClose);
        this->close();
        exit(EXIT_SUCCESS);
    }
    //此处调用show不会一闪而过
    qDebug()<<"net is: "<<v_version<<" and local is : "<<version<<endl;
    QProcess p;
    QString c = "taskkill    /F   /IM  Hiramclient.exe";
    p.execute(c);
    p.close();
    this->show();
    file.close();
}

//连接错误
void checkVersion::OnError(QNetworkReply::NetworkError)
{
    if(v_reply->error())
        qDebug()<<v_reply->errorString()<<endl;
    exit(EXIT_FAILURE);
}

//显示更新信息
void checkVersion::MessageShow()
{
    QByteArray mes_data=mes_reply->readAll();
    QString show_data(trUtf8( mes_data));
    ui->txtShow->setText(show_data);
}


void checkVersion::on_btnOk_clicked()
{
    this->close();
    MainWindow * w= new MainWindow();
    w->setWindowFlag(Qt::Window);
    w->show();
}


void checkVersion::on_btnCancel_clicked()
{
    this->close();
}
