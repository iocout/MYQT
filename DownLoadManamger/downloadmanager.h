#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include"mydownload.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initWindow();
    //转换单位
    QString transformUnit(qint64 bytes,bool isSpeed=false);
    //转换时间
    QString  transformTime(qint64 seconds);
    //下载完成，加载主进程
    void RunProcess();
private slots:
    void start(QString);

    void close();

    //    void stop();

    void onDownloadProcess(qint64 bytesReceived,qint64 bytesTotal);

    void onReplyFinished(int);

    void on_btnRetry_clicked();

    void onError();

private:
    Ui::MainWindow *ui;
    QString m_url;
    MyDownLoad * m_mydownload;
    uint m_timeInterval;
    qint64 m_currentDownload;
    qint64 m_intveralDownload;
    QTime m_timeRecord;
};

#endif // MAINWINDOW_H
