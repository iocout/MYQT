#ifndef FUNCTION_H
#define FUNCTION_H

#include <QModelIndex>
#include <QStandardItemModel>
#include <QTableView>
class function
{
public:
    function();
    bool modelSync(const QStandardItemModel &model_pre,QStandardItemModel &model_change);//model同步
    bool printexcel(const QTableView &tab);//打印方法
};



#endif // FUNCTION_H
