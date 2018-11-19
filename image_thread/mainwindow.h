#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFutureWatcher>
#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;
class QGridLayout;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void open();  // 打开目录，加载图片

    void showImage(int index);  // 显示图片

    void finished();  // 更新按钮状态

private:
    Ui::MainWindow *ui;
    QPushButton *m_pOpenButton;
    QPushButton *m_pCancelButton;
    QPushButton *m_pPauseButton;
    QVBoxLayout *m_pMainLayout;
    QGridLayout *m_pImagesLayout;
    QList<QLabel *> labels;
    QFutureWatcher<QImage> *m_pWatcher;
};

#endif // MAINWINDOW_H
