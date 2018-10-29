#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QNetworkReply;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    long  ZlibUncompress(QByteArray  &OutDecodeData, QByteArray InEncodeData,
//                     int   * nErrorCode = nullptr);
    void  ontest();
    QByteArray gUncompress(const QByteArray &data);
private:
    Ui::MainWindow *ui;
    QNetworkReply * reply;
    QByteArray data;
};

#endif // MAINWINDOW_H
