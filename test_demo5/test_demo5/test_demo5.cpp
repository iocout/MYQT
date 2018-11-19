#include "test_demo5.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QDebug>
#include <QFile>
#include <fstream>
#include <iostream>
#include <QFile>
#include <windows.h>
#include <QThread>
#include <QString>
#include <QObject>
#include "test_demo5.h"
#include "User.pb.h"
#include "json.pb.h"
using namespace std;
const QString test_demo5::m_url_ = "http://192.167.1.123:8081/c";
test_demo5::test_demo5(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_network=new QNetworkAccessManager(this);
	init();
}

test_demo5::~test_demo5()
{
	delete m_reply;
}

QByteArray & test_demo5::getdata() 
{
	return data;
}

void test_demo5::test()
{
	//检测版本
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	/*
	Test::Json json;
	fstream input("./log.txt ", ios::in | ios::binary);
	if (!input)
	{
		cout << "./log.txt" << ": file fail to open." << endl;
	}
	if (!json.ParseFromString(data.toStdString()))
	{
		cerr << "Fail to parse json." << endl;
		return;
	}
	input.close();
	QString test;
	QString msg=  QByteArray::fromStdString(json.msg());
	qint32 code = json.code();
	qDebug() << "code: " << code;
	test.append("code: ");
	test.append(QString::number(code,10));
	test.append("\n");
	test.append("msg:");
	test.append(msg);
	ui.textBrowser->setText(test);
	Test::Data data;
	int size_body = json.data().body_size();
	for (int i = 0; i < size_body; i++)
	{
		qDebug() << QString("%1").arg(i) << " ;barcode:" << QString::number(json.data().body(i).bodyid(),10);
	}
	*/
}

void test_demo5::init()
{
	QNetworkRequest	m_request;
	m_request.setUrl(test_demo5::m_url_);
	m_reply = m_network->get(m_request);

	connect(m_reply, &QNetworkReply::readyRead, [&]() {
		//qDebug() << "read";
		data.append(m_reply->readAll());
	});

	connect(m_reply, &QNetworkReply::finished, [&]() {
		QFile file("./log.txt");
		if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		{
			qDebug() << "error to open the file" << file.fileName();
		}
		file.write(data);
		file.close();
		qDebug() << "file write over";
		test();
	});

	connect(m_reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
		[=](QNetworkReply::NetworkError code) {
		qDebug() << "NETWORK ERROR: " << m_reply->errorString();
	});
}

