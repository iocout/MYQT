#include <QtWidgets/QApplication>
#include <fstream>
#include <iostream>
#include <QFile>
#include <windows.h>
#include <QThread>
#include <QString>
#include <QObject>
#include "test_demo5.h"
#include "json.pb.h"
#pragma  comment(lib,"libprotoc.lib")
#pragma  comment(lib,"libprotobuf.lib")
#pragma warning(disable:4996) 
#pragma execution_character_set("utf-8")

/*
void PromptForAddress(tutorial::Person * person)
{
	cout << "Enter persion ID number: ";w
	int id;
	cin >> id;
	person->set_id(id);
	cin.ignore(256, '\n');
	
	cout << "Enter name: ";
	getline(cin, *person->mutable_name());

	cout << "Enter email address (blank for none):";
	string email;
	getline(cin, email);
	if (!email.empty())
	{
		person->set_email(email);
	}

	while (true)
	{
		cout << "Enter a phone number (or leave blank to finish)";
		string number;
		getline(cin, number);
		if (number.empty())
		{
			break;
		}

		tutorial::Person::PhoneNumber * phone_number = person->add_phone();
		phone_number->set_number(number);

		cout << "Is this a mobile,home,or work phone ?";
		string type;
		getline(cin, type);
		if (type == "mobile")
		{
			phone_number->set_type(tutorial::Person::MOBILE);
		}
		else if (type=="home")
		{
			phone_number->set_type(tutorial::Person::HOME);
		}
		else if (type=="work")
		{
			phone_number->set_type(tutorial::Person::WORK);
		}
		else
		{
			cout << "Unknow phone tpye. Using default." << endl;
		}
	}
}
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	test_demo5 w;
	w.show();

	//检测版本
/*	GOOGLE_PROTOBUF_VERIFY_VERSION;*/

// 	fstream input("./log.txt", ios::in | ios::binary);
// 	if (!input)
// 	{
// 		cerr << "input open fail" << endl;
// 	}
// 	long size = sizeof(input);
// 	char  * buff = new char[size];
// 	input.read(buff, size);
// 	input.close();
	/*
	QObject::connect(w, &test_demo5::over, [] (){
		Json json;
		fstream input("./log.txt", ios::in | ios::binary);
		if (!input)
		{
			cout << "./log.txt" << ": file fail to open." << endl;
		}
		if (!json.ParseFromIstream(&input))
		{
			cerr << "Fail to parse json." << endl;
			return -1;
		}
		cout << "id is: " << json.id() << endl;
		cout << "name is :" << json.name() << endl;
	});
	*/
	//cout << "string : " << data<< endl;
//	QObject::connect(&w, &test_demo5::over, [&]() {
		//QString t_data = QString::fromLocal8Bit( w.getdata());
		//cout << "data>>>>>" << GBKToUTF8(t_data.toStdString( ));
		//w.setText(w.getdata().toStdString());
// 		qDebug() << "??????????\n" << data;
// 		m_json.ParseFromString(string((const char *)QString(data).toLocal8Bit()));
// 		//m_json.ParseFromString();
// 		cout << " std:" << string((const char *)QString(data).toLocal8Bit())<<endl;//成功	
// 		cout << endl;
// // 		cout << "code : " << m_json.code() << endl;
// // 		cout << "msg : " << m_json.msg() << endl;
// 		cout<<"_str:"<<m_json._str()<<endl;
//	});
	
	return a.exec();
}