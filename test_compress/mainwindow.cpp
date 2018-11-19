#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QTime>
#include <QFile>
#include "zip.h"


static const QString Url="http://localhost:8061/finishIn/getAllBody";
static QTime time_tt;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QNetworkAccessManager  * network=new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(Url);
    request.setRawHeader("Accept-Encoding", "gzip");
    reply=network->get(request);
    time_tt.start();
    connect(reply,&QNetworkReply::readyRead,[&](){
        data.append(reply->readAll());
    });
    connect(reply,&QNetworkReply::finished,[&](){
       // QByteArray M_data=qUncompress(data);
        QFile file("./log.txt");
        if(!file.open(QIODevice::WriteOnly| QIODevice::Truncate))
        {
            qDebug()<<" error to open file";
            exit(EXIT_FAILURE);
        }
        file.write(data);
        file.flush();
        file.close();
        qDebug()<<"finished";
        qDebug()<<"all use time: "<<time_tt.elapsed()/1000<<" S ";
        ontest();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ontest()
{
    QFile g_file("./log.txt");
    if(!g_file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error to open get file";
        exit(EXIT_FAILURE);
    }
    QByteArray tst=gUncompress(g_file.readAll());
    QFile m_file("./get.txt");
    if(!m_file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"error to open get file";
        exit(EXIT_FAILURE);
    }
    m_file.write(tst);
    m_file.close();
}


QByteArray MainWindow::gUncompress(const QByteArray &data)
{
    if (data.size() <= 4) {
        qWarning("gUncompress: Input data is truncated");
        return QByteArray();
    }

    QByteArray result;

    int ret;
    z_stream strm;
    static const int CHUNK_SIZE = 1024;
    char out[CHUNK_SIZE];

    /* allocate inflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = data.size();
    strm.next_in = (Bytef*)(data.data());
    ret = inflateInit2(&strm, 15 +  32); // gzip decoding
    if (ret != Z_OK)
        return QByteArray();

    // run inflate()
    do {
        strm.avail_out = CHUNK_SIZE;
        strm.next_out = (Bytef*)(out);

        ret = inflate(&strm, Z_NO_FLUSH);
        Q_ASSERT(ret != Z_STREAM_ERROR);  // state not clobbered

        switch (ret) {
        case Z_NEED_DICT:
            ret = Z_DATA_ERROR;     // and fall through
        case Z_DATA_ERROR:
        case Z_MEM_ERROR:
            (void)inflateEnd(&strm);
            return QByteArray();
        }
        result.append(out, CHUNK_SIZE - strm.avail_out);
    } while (strm.avail_out == 0);

    // clean up and return
    inflateEnd(&strm);
    return result;
}
