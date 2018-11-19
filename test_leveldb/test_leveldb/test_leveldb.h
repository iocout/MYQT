#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test_leveldb.h"

class test_leveldb : public QMainWindow
{
	Q_OBJECT

public:
	test_leveldb(QWidget *parent = Q_NULLPTR);
	void init();
private:
	Ui::test_leveldbClass ui;
};
