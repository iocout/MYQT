#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

struct code{
    QString codes;  //单据号
    bool isCheck;   //是否审核
    };

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initStyle();
    void getdata();
//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;//重新实现

private slots:
    void on_btn_add_clicked();

    void on_btn_edit_clicked();

    void on_btn_del_clicked();

    void on_btn_save_clicked();

    void on_btn_check_clicked();

    void on_btn_print_clicked();

    void on_btn_copy_clicked();

    void on_pushButton_5_clicked();

    void on_btn_cancel_clicked();

    void on_btn_excel_clicked();

    void onListContextMenu(const QPoint & );//右键菜单

    void on_actionadd_triggered();

    void on_actionrow_triggered();

private:
    void vector(); //初始化表头标题
    void initheader(); //定义表头大小
    void  ischeckenableBtn(bool );//按钮状态使能
private:
    Ui::MainWindow *ui;
    QStandardItemModel * model;//正在使用的model
    QStandardItemModel * backup_model;//备份的model
    code *  pageflag;   //包含单号和状态
    bool status;  //是否可编辑状态

};

#endif // MAINWINDOW_H
