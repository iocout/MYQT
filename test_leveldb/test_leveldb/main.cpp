#include "test_leveldb.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test_leveldb w;
	w.init();
	w.show();
	return a.exec();
}
