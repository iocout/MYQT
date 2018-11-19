#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test_demo5.h"
#include <QNetworkReply>
class QByteArray;
class test_demo5 : public QMainWindow
{
	Q_OBJECT

signals:
	void over();
public:
	test_demo5(QWidget *parent = Q_NULLPTR);
	~test_demo5();
	QByteArray & getdata() ;
	void test();
	void init();

private:
	Ui::test_demo5Class ui;
	QNetworkReply * m_reply;
	static const QString m_url_;
	QNetworkAccessManager *  m_network;
	QByteArray data;
};
