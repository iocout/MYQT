#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include<QUrl>


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
    QByteArray  ParseIni();//解析HiramClient.ini中的路径
    void Closewin();//关闭主界面
private slots:
    void OnError(QNetworkReply::NetworkError);

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void Showupdata();//检测版本

    void TimeCheck();//定时检查任务
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager * c_network;
    QNetworkReply * c_reply;
    QNetworkReply * msgreply;
    QString uproad;
    QNetworkRequest request;
};

#endif // MAINWINDOW_H
