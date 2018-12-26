/*
Interpolation class 为主界面，用来选择待处理图像和处理方法。被主界面Interpolation 调用
*/

#include "Interpolation.h"

using namespace std;
Interpolation::Interpolation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("图像变换"));
}

void Interpolation::open()  //选择图片
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image File(*.jpg *.png *.bmp)"));
	if (path.length() == 0) {
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
	}
	else {
		ui.lineEdit->setText(path);
		QString tmpPath = path;
		tmpPath.replace("\\", "\\\\");   //对图片路径格式进行转换
		imgname = tmpPath.toStdString();
	}
	return;
}

void Interpolation::on_pushButton_clicked() {  //点击按钮选择图片
   open();
}

void Interpolation::on_pushButton_2_clicked() {  
	style = 1;  //旋转
	if (check()) {
		mydialog* dialog = new mydialog(style, imgname);
		dialog->setWindowTitle(QString::fromLocal8Bit("旋转变换"));
		dialog->exec();
	}
}

void Interpolation::on_pushButton_3_clicked() {
	style = 2;  //水波纹
	if (check()) {
		mydialog* dialog = new mydialog(style, imgname);
		dialog->setWindowTitle(QString::fromLocal8Bit("水波纹变换"));
		dialog->exec();
	}
}

void Interpolation::on_pushButton_4_clicked() {
	style = 3;  //B样条插值
	if (check()) {
		Bspline_Dialog * bspline = new Bspline_Dialog(imgname);
		bspline->exec();
	}
}

bool Interpolation::check() {
	if (imgname.empty()) {//未选择图片

		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("请选择一张图片！"));
		msgBox.exec();
		msgBox.setWindowTitle(QString::fromLocal8Bit("警告"));
		return false;
	}
	 return true;
}
