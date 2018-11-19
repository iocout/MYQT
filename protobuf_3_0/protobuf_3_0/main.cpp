#include "protobuf_3_0.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	protobuf_3_0 w;
	w.show();
	return a.exec();
}
