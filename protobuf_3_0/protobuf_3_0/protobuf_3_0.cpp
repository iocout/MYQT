#include "protobuf_3_0.h"
#include "User.pb.h"
#include <QFile>
#include <QDebug>

using namespace std;
protobuf_3_0::protobuf_3_0(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Optry::User user;
	user.set_id(7);
	qDebug() << user.id();
}
