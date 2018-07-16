#ifndef METHOD_H
#define METHOD_H

#include <QObject>
#include<QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
class Method:public QObject
{
    Q_OBJECT
public:
    explicit Method(QObject *parent = nullptr);
    ~Method();

    void setDownInto(bool inSupportBreakPoint);//开始
    QString  downloadFile(QString url);//下载
    QString getDownloadUrl();//取得下载地址
    void reset();//重置
    void stopWork();
    void removeFile(QString fileName);
    void stopDownLoad();
    void closeDownload();

signals:
    void signalDownloadProcess(qint64,qint64);
    void signalReplyFinished(int);
    void signalDownloadError();

private slots:
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onReadyRead();
    void onFinished();
    void onError(QNetworkReply::NetworkError code);


private:
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_reply;//响应
    QUrl m_url;
    QString m_fileName;
    bool m_isSupportBreakPoint;
    qint64 m_bytesReceived;
    qint64 m_bytesTotal;
    qint64 m_bytesCurrentReceived;//从哪里开始（HTTP请求变量）
    QByteArray bytes;
    bool m_isStop;

};



#endif // METHOD_H
