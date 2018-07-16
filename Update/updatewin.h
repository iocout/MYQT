#ifndef UPDATEWIN_H
#define UPDATEWIN_H

#include <QWidget>
#include<QNetworkReply>
#include "method.h"

namespace Ui {
class UpdateWin;
}

class UpdateWin : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateWin(QWidget *parent = 0);
    ~UpdateWin();
    void setDownUrl(const QString url);

private:
    void initWindow();
    //转换单位
    QString transformUnit(qint64 bytes,bool isSpeed=false);
    //转换时间
    QString  transformTime(qint64 seconds);
    //下载完成，加载主进程
    void RunProcess();
private slots:
    void start();

    void close();

    void onDownloadProcess(qint64 bytesReceived,qint64 bytesTotal);

    void onReplyFinished(int);

    void on_btnRetry_clicked();

    void onError();

private:
    Ui::UpdateWin *ui;
    QString  m_url;
    Method * m_method;
    uint m_timeInterval;
    qint64 m_currentDownload;
    qint64 m_intveralDownload;
    QTime m_timeRecord;

};

#endif // UPDATEWIN_H
