#include "method.h"
#include<QFile>
#include<QDebug>
#include<QFileInfo>
#include<QDir>
#include<QUrl>
#include<QString>
#include<QObject>
#include<QDir>
#include"JlCompress.h"

static const QString DOWNLOAD_FILE_SUFFIX = "_tmp";

Method::Method(QObject *parent) :
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

Method::~Method()
{
}

//设置是否支持断点续传
void Method::setDownInto(bool inSupportBreakPoint)
{
    m_isSupportBreakPoint=inSupportBreakPoint;
}


//开始下载文件
QString  Method::downloadFile(QString url)
{
    //防止多次下载
    if(m_isStop)
    {
        m_isStop=false;
        m_url=QUrl(url);
        if(!m_url.isValid()){
            qDebug()<<"Invalid URL:"<<m_url.toString()<<endl;
            return "Invalid URL";
        }
        QFileInfo fileInfo(m_url.path());
        QString fileName = fileInfo.fileName();
        m_fileName="tmp/"+fileName;
        qDebug()<<" fileName: "<<m_fileName<<endl;
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
    return NULL;
}

//下载进度信息
void Method::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if(!m_isStop)
    {
        m_bytesReceived=bytesReceived;
        m_bytesTotal=bytesTotal;
        emit signalDownloadProcess(qint64(m_bytesReceived+m_bytesCurrentReceived),qint64(m_bytesTotal+m_bytesCurrentReceived));
    }
}

//获取下载内容，保存到文件中
void Method::onReadyRead()
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
void Method::onFinished()
{
    m_isStop=true;
    QVariant statusCode=m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"get finished status: "<<statusCode.toString()<<endl;
    if(m_reply->error() ==QNetworkReply::NoError)
    {
        //删除原来的EXE文件，重命名临时文件
        QFileInfo fileInfo(m_fileName);
        if(fileInfo.exists())
        {
            QString realname="HiramClient.exe";
            removeFile(realname);
            //zip -> exe
            JlCompress zip;
            QDir dir;
            QString road =dir.currentPath();
            zip.extractDir(m_fileName,"");
            removeFile(m_fileName);//移除zip文件
            //更换ini文件
            removeFile("update.ini");
            QFile::rename("tmp/update.ini","update.ini");
        }
    }
    else
    {
        //输出错误
        QString strError=m_reply->errorString();
        qDebug()<<"__________1 "+strError<<endl;
        closeDownload();
    }
    emit signalReplyFinished(statusCode.toInt());//将状态位发送出去
}

//下载错误，关闭下载，上报错误，可自定义上报错误类型进行上报
void Method::onError(QNetworkReply::NetworkError)
{
    QString strError=m_reply->errorString();
    qDebug() << "__________2 " + strError;
    closeDownload();
    emit signalDownloadError();
}

//停止
void Method::stopWork()
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
void Method::stopDownLoad()
{
    //防止多次按下
    if(!m_isStop)
    {
        m_bytesCurrentReceived+=m_bytesReceived;
        stopWork();
    }
}

//重置
void Method::reset()
{
    m_bytesCurrentReceived=0;
    m_bytesReceived=0;
    m_bytesTotal=0;
}

//删除文件
void Method::removeFile(QString fileName)
{
    QFileInfo fileInfo(fileName);
    if(fileInfo.exists())
    {
        QFile::remove(fileName);
    }
}

// 关闭下载，重置参数，并删除下载的临时文件;
void Method::closeDownload()
{
    stopWork();
    reset();
    removeFile(m_fileName);
}


QString Method::getDownloadUrl()
{
    return m_url.toString();
}
