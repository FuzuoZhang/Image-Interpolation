/*
Interpolation class Ϊ�����棬����ѡ�������ͼ��ʹ���������������Interpolation ����
*/

#include "Interpolation.h"

using namespace std;
Interpolation::Interpolation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("ͼ��任"));
}

void Interpolation::open()  //ѡ��ͼƬ
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image File(*.jpg *.png *.bmp)"));
	if (path.length() == 0) {
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
	}
	else {
		ui.lineEdit->setText(path);
		QString tmpPath = path;
		tmpPath.replace("\\", "\\\\");   //��ͼƬ·����ʽ����ת��
		imgname = tmpPath.toStdString();
	}
	return;
}

void Interpolation::on_pushButton_clicked() {  //�����ťѡ��ͼƬ
   open();
}

void Interpolation::on_pushButton_2_clicked() {  
	style = 1;  //��ת
	if (check()) {
		mydialog* dialog = new mydialog(style, imgname);
		dialog->setWindowTitle(QString::fromLocal8Bit("��ת�任"));
		dialog->exec();
	}
}

void Interpolation::on_pushButton_3_clicked() {
	style = 2;  //ˮ����
	if (check()) {
		mydialog* dialog = new mydialog(style, imgname);
		dialog->setWindowTitle(QString::fromLocal8Bit("ˮ���Ʊ任"));
		dialog->exec();
	}
}

void Interpolation::on_pushButton_4_clicked() {
	style = 3;  //B������ֵ
	if (check()) {
		Bspline_Dialog * bspline = new Bspline_Dialog(imgname);
		bspline->exec();
	}
}

bool Interpolation::check() {
	if (imgname.empty()) {//δѡ��ͼƬ

		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("��ѡ��һ��ͼƬ��"));
		msgBox.exec();
		msgBox.setWindowTitle(QString::fromLocal8Bit("����"));
		return false;
	}
	 return true;
}
