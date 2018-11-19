#include "test_leveldb.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <leveldb/db.h>
#include <QMap>
#pragma comment(lib,"leveldb.lib") 
#pragma comment(lib,"Shlwapi.lib") 

using namespace std;
test_leveldb::test_leveldb(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void test_leveldb::init()
{
	leveldb::DB *  db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "/db/test/", &db);  //通过状态位来判断
	Q_ASSERT(status.ok());
	
	std::string value("value");
	std::string key = "key";
	//添加key value
	status = db->Put(leveldb::WriteOptions(), key, value);
	Q_ASSERT(status.ok());
	//查询
	std::string value2;
	status = db->Get(leveldb::ReadOptions(), key, &value2);
	std::cout << "value2:"<<value2<<std::endl;
	//修改(由添加和删除合起来实现)
	std::string key2 = "key2";
	status = db->Put(leveldb::WriteOptions(), key2, value);
	//status = db->Delete(leveldb::WriteOptions(), key);
	std::string value3;
	std::cout << "key1:" << db->Get(leveldb::ReadOptions(), key,&value3).ToString()<<std::endl;  //OK????
	delete db;
}
