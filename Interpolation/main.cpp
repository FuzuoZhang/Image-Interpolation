#include "Interpolation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Interpolation w;
	w.show();
	return a.exec();
}
