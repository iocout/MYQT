#include "updatewin.h"
#include "ui_updatewin.h"

UpdateWin::UpdateWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateWin)
{
    ui->setupUi(this);
}

UpdateWin::~UpdateWin()
{
    delete ui;
}
