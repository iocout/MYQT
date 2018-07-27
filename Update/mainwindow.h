#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include<QUrl>
#include<QLocalServer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void TimeCkVersion();
private:
    void Initnetwork();

    QByteArray  ParseIni();//解析HiramClient.ini中的路径

    void Closewin();//关闭主界面

    void TimeCkversion();
private slots:
    void OnError(QNetworkReply::NetworkError);

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void Showupdata();//检测版本

    void initLocalConnection();//服务器模型创建单实例

    void newLocalConnection();//服务器模型创建单实例

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager * c_network;
    QNetworkReply * c_reply;
    QNetworkReply * msgreply;
    QString uproad;
    QNetworkRequest c_request;
    bool firstopen;
    bool isRuning;//程序是否已经运行
    QLocalServer * server;
};


#endif // MAINWINDOW_H
