/*
Display_Dialog class 用来显示处理后的图像，提供保存功能。被mydialog 和 Bspline_Dialog 所调用。
*/

#include "Display_Dialog.h"

Display_Dialog::Display_Dialog(Mat image,QWidget *parent)
	:image(image), QDialog(parent)
{
	ui.setupUi(this);
	Mat imagergb;
	//显示图像
	cv::cvtColor(image, imagergb, CV_BGR2RGB);
	qimage= QImage((const unsigned char*)(imagergb.data), imagergb.cols, imagergb.rows, QImage::Format_RGB888);

	ui.mylabel->setPixmap(QPixmap::fromImage(qimage));

	ui.mylabel->resize(ui.mylabel->pixmap()->size());

	ui.mylabel->show();
}

Display_Dialog::~Display_Dialog()
{
}

void Display_Dialog::on_pushButton_clicked() {  //点击按钮后保存图片
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
		"untitled.bmp",tr("Images (*.png *.xpm *.jpg *.bmp)"));
	if (!fileName.isEmpty()) {
		String filename = fileName.toStdString();
		cv::imwrite(filename, image);
	}
}