#ifndef UPDATEWIN_H
#define UPDATEWIN_H

#include <QWidget>

namespace Ui {
class UpdateWin;
}

class UpdateWin : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateWin(QWidget *parent = 0);
    ~UpdateWin();

private:
    Ui::UpdateWin *ui;
};

#endif // UPDATEWIN_H
