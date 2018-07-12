#include "mydownload.h"
#include<QFile>
#include<QDebug>
#include<QFileInfo>
#include<QDir>
#include<QUrl>
#include<QString>
#include<QObject>


static const QString DOWNLOAD_FILE_SUFFIX = "_tmp";

MyDownLoad::MyDownLoad(QObject *parent) :
    QObject(parent),
    m_networkManager(NULL),
    m_url(QUrl("")),
    m_fileName(""),
    m_isSupportBreakPoint(false),
    m_bytesReceived(0),
    m_bytesTotal(0),
    m_bytesCurrentReceived(0),
    m_isStop(true)
{
    m_networkManager =new QNetworkAccessManager(this);
}

MyDownLoad::~MyDownLoad()
{
}

//设置是否支持断点续传
void MyDownLoad::setDownInto(bool inSupportBreakPoint)
{
    m_isSupportBreakPoint=inSupportBreakPoint;
}

QString MyDownLoad::getDownloadUrl()
{
    return m_url.toString();
}

//开始下载文件
void MyDownLoad::downloadFile(QString url, QString fileName)
{
    //防止多次下载
    if(m_isStop)
    {
        m_isStop=false;
        m_url=QUrl(url);
        if(!m_url.isValid()){
            //TODO 显示路径名错误
            qDebug()<<"Invalid URL:"<<m_url.toString()<<endl;
            return ;
        }
        QFileInfo fileInfo(m_url.path());
        QString fileName = fileInfo.fileName();
        m_fileName="tmp/"+fileName+DOWNLOAD_FILE_SUFFIX;
        QString m_updatefile="tmp/update.ini"+DOWNLOAD_FILE_SUFFIX;
        qDebug()<<" fileName: "<<m_updatefile<<endl;
        // 如果当前下载的字节数为0那么说明未下载过或者重新下载
        // 则需要检测本地是否存在之前下载的临时文件，如果有则删除
        if(m_bytesCurrentReceived<=0)
        {
            removeFile(m_fileName);
        }
        QNetworkRequest request;
        request.setUrl(m_url);
        //如果支持断点续传，则设置请求头信息
        if(m_isSupportBreakPoint){
            QString strRange=QString("bytes=%1-").arg(m_bytesCurrentReceived);
            request.setRawHeader("Range",strRange.toLatin1());
        }
        m_reply=m_networkManager->get(request);//获取响应
        bytes=m_reply->readAll();
        qDebug()<<"get the request:"<<bytes;
        connect(m_reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
        connect(m_reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
        connect(m_reply,SIGNAL(finished()),this,SLOT(onFinished()));
        connect(m_reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(onError(QNetworkReply::NetworkError)));
        qDebug()<<"connect success\n";
    }
}

//下载进度信息
void MyDownLoad::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if(!m_isStop)
    {
        m_bytesReceived=bytesReceived;
        m_bytesTotal=bytesTotal;
        //更新下载进度;(加上 m_bytesCurrentReceived 是为了断点续传时之前下载的字节)
        emit signalDownloadProcess(qint64(m_bytesReceived+m_bytesCurrentReceived),qint64(m_bytesTotal+m_bytesCurrentReceived));
    }
}

//获取下载内容，保存到文件中
void MyDownLoad::onReadyRead()
{
    if(!m_isStop)
    {
        QFile file(m_fileName);
        if(file.open(QIODevice::WriteOnly| QIODevice::Append))
        {
            file.write(m_reply->readAll());
        }else{
            qDebug()<<"file open fail"<<endl;
        }
        file.close();
    }
}


//下载完成
void MyDownLoad::onFinished()
{
    m_isStop=true;
    QVariant statusCode=m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"get finished status: "<<statusCode.toString()<<endl;
    if(m_reply->error() ==QNetworkReply::NoError)
    {
        //删除原来的文件，重命名临时文件
        QFileInfo fileInfo(m_fileName);
        if(fileInfo.exists())
        {
            QString realname="HiramClient.exe";
            QString realupdate="update.ini";
            QFileInfo realfile(realname);
            QFileInfo updatefile(realupdate);
            QString tem_update("tmp\\update.ini_tmp");
            if(realfile.exists())
            {
                removeFile(realname);
                removeFile(realupdate);
            }
            QFile::rename(m_fileName,realname);
            QFile::rename(tem_update,realupdate);
        }
    }
    else
    {
        //输出错误
        QString strError=m_reply->errorString();
        qDebug()<<"_____________1 "+strError<<endl;
        closeDownload();
    }
    emit signalReplyFinished(statusCode.toInt());//将状态位发送出去
}

//下载错误，关闭下载，上报错误，可自定义上报错误类型进行上报
void MyDownLoad::onError(QNetworkReply::NetworkError)
{

    QString strError=m_reply->errorString();
    qDebug() << "__________2 " + strError;
    closeDownload();
    emit signalDownloadError();
}

//停止
void MyDownLoad::stopWork()
{
    m_isStop=true;
    if(m_reply!=NULL)
    {
        disconnect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
        disconnect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        disconnect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
        disconnect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
        m_reply->abort();
        m_reply->deleteLater();//在线程中调用此函数将其销毁
        m_reply = NULL;
    }
}


//暂停
void MyDownLoad::stopDownLoad()
{
    //防止多次按下
    if(!m_isStop)
    {
        m_bytesCurrentReceived+=m_bytesReceived;
        stopWork();
    }
}

//重置
void MyDownLoad::reset()
{
    m_bytesCurrentReceived=0;
    m_bytesReceived=0;
    m_bytesTotal=0;
}


//删除文件
void MyDownLoad::removeFile(QString fileName)
{
    //
    QFileInfo fileInfo(fileName);
    if(fileInfo.exists())
    {
        QFile::remove(fileName);
    }
}

// 关闭下载，重置参数，并删除下载的临时文件;
void MyDownLoad::closeDownload()
{
    stopWork();
    reset();
    removeFile(m_fileName);
}
