#include "updatewin.h"
#include "ui_updatewin.h"
#include "method.h"
#include<QMessageBox>
#include<QThread>
#include<QProcess>


static const qint64 UNIT_KB=1024;
static const qint64 UNIT_MB=1024*1024;
static const qint64 UNIT_GB=1024*1024*1024;
static const qint32 TIME_INTERVAL=300;
static const QString DOWN_FILE_NAME="/HiramClient.zip";

UpdateWin::UpdateWin(QWidget *parent) :
    QWidget(parent),
    m_method(NULL),
    m_url(""),
    m_timeInterval(0),
    m_currentDownload(0),
    m_intveralDownload(0),
    ui(new Ui::UpdateWin)
{
    ui->setupUi(this);
    initWindow();
}

UpdateWin::~UpdateWin()
{
    delete ui;
}

void UpdateWin::initWindow()
{
    ui->progressBar->setValue(0);
    ui->progressBar->setStyleSheet(	"QProgressBar{border: 30px;color: white;text-align: center;background: "
                                    "rgb(68, 69, 73);} QProgressBar::chunk {border: none;background: rgb(0, 160, 230);}");
}

//获取下载路劲
void  UpdateWin::setDownUrl(const QString url)
{
    m_url=url;
    m_url+=DOWN_FILE_NAME;
    qDebug()<<" down load url is "<<m_url<<endl;
    start();
}

//开始
void UpdateWin::start()
{
    qDebug()<<"m_url in start is :"<<m_url<<endl;
    if(m_method==NULL)
    {
        m_method =new Method();
        connect(m_method,&Method::signalDownloadProcess,this,&UpdateWin::onDownloadProcess);
        connect(m_method,&Method::signalReplyFinished,this,&UpdateWin::onReplyFinished);
        connect(m_method,&Method::signalDownloadError,this,&UpdateWin::onError);
    }
    QString url=m_method->getDownloadUrl();
    if(url!=m_url)
        m_method->reset();//先恢复
    m_method->setDownInto(true);//断点续传
    QString downreturn =m_method->downloadFile(m_url);
    if(downreturn!=NULL)
    {
        qDebug()<<"downreturn"<<downreturn<<endl;
        ui->labStatus->setText(downreturn);
    }
    m_timeRecord.start();//开始计时
    m_timeInterval=0;
    ui->labStatus->setText("正在下载");//QStringLiteral
}

//重试
void UpdateWin::on_btnRetry_clicked()
{
    close();
    start();
}

//关闭
void UpdateWin::close()
{
    if(m_method == NULL) return;
    m_method->closeDownload();
    ui->progressBar->setValue(0);
    ui->labelSpeed->setText("0KB/S");
    ui->labelRemainTime->setText("0S");
    ui->labStatus->setText("正在重试");
    ui->labelCurrentDownload->setText("0 B");
    ui->labelFileSize->setText("0 B");
}


//更新下载进度
void UpdateWin::onDownloadProcess(qint64 bytesReceived, qint64 bytesTotal)
{
    //更新进度条
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesReceived);
    m_intveralDownload+=bytesReceived - m_currentDownload ;
    m_currentDownload=bytesReceived;
    uint timeNow=m_timeRecord.elapsed();//start to now
    //超过0.3S更新一次进度
    if(timeNow-m_timeInterval>TIME_INTERVAL)
    {
        qint64 ispeed=m_intveralDownload *1000/(timeNow-m_timeInterval);
        QString strSpeed = transformUnit(ispeed, true);
        ui->labelSpeed->setText(strSpeed);
        // 剩余时间
        qint64 timeRemain = (bytesTotal - bytesReceived) / ispeed;
        ui->labelRemainTime->setText(transformTime(timeRemain));
        ui->labelCurrentDownload->setText(transformUnit(m_currentDownload));
        ui->labelFileSize->setText(transformUnit(bytesTotal));
        m_intveralDownload = 0;
        m_timeInterval = timeNow;
    }
}

//返回状态码
void UpdateWin::onReplyFinished(int statusCode)
{
    if (statusCode >= 300 && statusCode < 400)
    {
        qDebug() << "Download Failed";
        ui->labStatus->setText("下载失败，请重试");
    }
    else
    {
        qDebug() << "Download Success";
        ui->labStatus->setText("下载成功");
    }
    qDebug()<<"statusCode:"<<statusCode<<endl;
    RunProcess();
}



//时间转换
QString UpdateWin::transformTime(qint64 seconds)
{
    QString strValue;
    QString strSpacing(" ");
    if (seconds <= 0)
    {
        strValue = QString("%1s").arg(0);
    }
    else if (seconds < 60)
    {
        strValue = QString("%1s").arg(seconds);
    }
    else if (seconds < 60 * 60)
    {
        int nMinute = seconds / 60;
        int nSecond = seconds - nMinute * 60;

        strValue = QString("%1m").arg(nMinute);

        if (nSecond > 0)
            strValue += strSpacing + QString("%1s").arg(nSecond);
    }
    else if (seconds < 60 * 60 * 24)
    {
        int nHour = seconds / (60 * 60);
        int nMinute = (seconds - nHour * 60 * 60) / 60;
        int nSecond = seconds - nHour * 60 * 60 - nMinute * 60;

        strValue = QString("%1h").arg(nHour);

        if (nMinute > 0)
            strValue += strSpacing + QString("%1m").arg(nMinute);

        if (nSecond > 0)
            strValue += strSpacing + QString("%1s").arg(nSecond);
    }
    else
    {
        int nDay = seconds / (60 * 60 * 24);
        int nHour = (seconds - nDay * 60 * 60 * 24) / (60 * 60);
        int nMinute = (seconds - nDay * 60 * 60 * 24 - nHour * 60 * 60) / 60;
        int nSecond = seconds - nDay * 60 * 60 * 24 - nHour * 60 * 60 - nMinute * 60;

        strValue = QString("%1d").arg(nDay);

        if (nHour > 0)
            strValue += strSpacing + QString("%1h").arg(nHour);

        if (nMinute > 0)
            strValue += strSpacing + QString("%1m").arg(nMinute);

        if (nSecond > 0)
            strValue += strSpacing + QString("%1s").arg(nSecond);
    }

    return strValue;
}


//错误
void UpdateWin::onError()
{
    ui->labStatus->setText("下载失败，请重试");
}

//关闭当前进程，加载主进程
void UpdateWin::RunProcess()
{
    QThread::msleep(1000);
    QProcess exe;
    QString DirPath= qApp->applicationDirPath();
    DirPath.append("/HiramClient.exe");
    //当前进程与外部进程脱钩
    bool success=exe.startDetached(DirPath,QStringList(DirPath));
    qDebug()<<"this path"<<DirPath<<endl;
    this->deleteLater();
}


// 转换单位;
QString UpdateWin::transformUnit(qint64 bytes , bool isSpeed)
{
    QString strUnit = " B";
    if (bytes <= 0)
    {
        bytes = 0;
    }
    else if (bytes < UNIT_KB)
    {
    }
    else if (bytes < UNIT_MB)
    {
        bytes /= UNIT_KB;
        strUnit = " KB";
    }
    else if (bytes < UNIT_GB)
    {
        bytes /= UNIT_MB;
        strUnit = " MB";
    }
    else if (bytes > UNIT_GB)
    {
        bytes /= UNIT_GB;
        strUnit = " GB";
    }

    if (isSpeed)
    {
        strUnit += "/S";
    }
    return QString("%1%2").arg(bytes).arg(strUnit);
}

