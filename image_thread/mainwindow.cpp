#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QFileDialog>
#include <QtConcurrent/QtConcurrentMap>
#include <QStandardPaths>
#include <QHBoxLayout>
#include <qmath.h>

const int c_nImageSize = 100;

// 缩放图片
QImage scale(const QString &imageFileName)
{
    QImage image(imageFileName);
    return image.scaled(QSize(c_nImageSize, c_nImageSize), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(QStringLiteral(":/image/image/桌面1.jpg")));
    setWindowTitle(QStringLiteral("Qt之QFutureWatcher"));
    resize(800, 600);

    // 初始化控件
    m_pWatcher = new QFutureWatcher<QImage>(this);
    m_pOpenButton = new QPushButton("qrc:/image/1.jpg");
    m_pCancelButton = new QPushButton(QStringLiteral("取消"));
    m_pPauseButton = new QPushButton(QStringLiteral("暂停/恢复"));
    QProgressBar *pProgressBar = new QProgressBar(this);

    m_pCancelButton->setEnabled(false);
    m_pPauseButton->setEnabled(false);

    // 布局
    QHBoxLayout *pButtonLayout = new QHBoxLayout();
    pButtonLayout->addWidget(m_pOpenButton);
    pButtonLayout->addWidget(m_pCancelButton);
    pButtonLayout->addWidget(m_pPauseButton);
    pButtonLayout->addStretch();
    pButtonLayout->setSpacing(10);
    pButtonLayout->setMargin(0);

    m_pImagesLayout = new QGridLayout();

    m_pMainLayout = new QVBoxLayout();
    m_pMainLayout->addLayout(pButtonLayout);
    m_pMainLayout->addWidget(pProgressBar);
    m_pMainLayout->addLayout(m_pImagesLayout);
    m_pMainLayout->addStretch();
    m_pMainLayout->setSpacing(10);
    m_pMainLayout->setContentsMargins(10, 10, 10, 10);
    this->centralWidget()->setLayout(m_pMainLayout);

    // 连接信号槽 - 加载、显示进度、打开、取消等操作
    connect(m_pWatcher, SIGNAL(resultReadyAt(int)), SLOT(showImage(int)));
    connect(m_pWatcher, SIGNAL(progressRangeChanged(int,int)), pProgressBar, SLOT(setRange(int,int)));
    connect(m_pWatcher, SIGNAL(progressValueChanged(int)), pProgressBar, SLOT(setValue(int)));
    connect(m_pWatcher, SIGNAL(finished()), SLOT(finished()));
    connect(m_pOpenButton, SIGNAL(clicked()), SLOT(open()));
    connect(m_pCancelButton, SIGNAL(clicked()), m_pWatcher, SLOT(cancel()));
    connect(m_pPauseButton, SIGNAL(clicked()), m_pWatcher, SLOT(togglePaused()));
}

MainWindow::~MainWindow()
{
    m_pWatcher->cancel();
    m_pWatcher->waitForFinished();
    delete ui;
}

// 打开目录，加载图片
void MainWindow::open()
{
    // 如果已经加载图片，取消并进行等待
    if (m_pWatcher->isRunning()) {
        m_pWatcher->cancel();
        m_pWatcher->waitForFinished();
    }

    // 显示一个文件打开对话框
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      QStringLiteral("选择图片"),
                                                      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                                                      "*.jpg *.png");

    if (files.count() == 0)
        return;

    // 做一个简单的布局
    qDeleteAll(labels);
    labels.clear();

    int dim = qSqrt(qreal(files.count())) + 1;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            QLabel *pLabel = new QLabel(this);
            pLabel->setFixedSize(c_nImageSize, c_nImageSize);
            m_pImagesLayout->addWidget(pLabel, i, j);
            labels.append(pLabel);
        }
    }

    // 使用 mapped 来为 files 运行线程安全的 scale 函数
    m_pWatcher->setFuture(QtConcurrent::mapped(files, scale));

    m_pOpenButton->setEnabled(false);
    m_pCancelButton->setEnabled(true);
    m_pPauseButton->setEnabled(true);
}

// 显示图片
void MainWindow::showImage(int index)
{
    labels[index]->setPixmap(QPixmap::fromImage(m_pWatcher->resultAt(index)));
}

// 更新按钮状态
void MainWindow::finished()
{
    m_pOpenButton->setEnabled(true);
    m_pCancelButton->setEnabled(false);
    m_pPauseButton->setEnabled(false);
}

