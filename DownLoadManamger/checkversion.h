#ifndef CHECKVERSION_H
#define CHECKVERSION_H

#include <QWidget>
#include<QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class checkVersion;
}

class checkVersion : public QWidget
{
    Q_OBJECT

public:
    explicit checkVersion(QWidget *parent = 0);
    ~checkVersion();
    bool showupdata();//检测版本
private slots:     
    void OnError(QNetworkReply::NetworkError);

    void isversion();

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void MessageShow();

private:
    Ui::checkVersion *ui;
    QNetworkReply * v_reply;
    QNetworkReply * mes_reply;
    QNetworkAccessManager * v_network;
    QUrl url;
    QUrl mesUrl;
};

#endif // CHECKVERSION_H
