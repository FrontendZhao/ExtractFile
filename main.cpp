#include "extractfile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ExtractFile w;
	w.show();
	return a.exec();
}
