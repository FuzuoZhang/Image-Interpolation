/*
Display_Dialog class ������ʾ������ͼ���ṩ���湦�ܡ���mydialog �� Bspline_Dialog �����á�
*/

#include "Display_Dialog.h"

Display_Dialog::Display_Dialog(Mat image,QWidget *parent)
	:image(image), QDialog(parent)
{
	ui.setupUi(this);
	Mat imagergb;
	//��ʾͼ��
	cv::cvtColor(image, imagergb, CV_BGR2RGB);
	qimage= QImage((const unsigned char*)(imagergb.data), imagergb.cols, imagergb.rows, QImage::Format_RGB888);

	ui.mylabel->setPixmap(QPixmap::fromImage(qimage));

	ui.mylabel->resize(ui.mylabel->pixmap()->size());

	ui.mylabel->show();
}

Display_Dialog::~Display_Dialog()
{
}

void Display_Dialog::on_pushButton_clicked() {  //�����ť�󱣴�ͼƬ
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
		"untitled.bmp",tr("Images (*.png *.xpm *.jpg *.bmp)"));
	if (!fileName.isEmpty()) {
		String filename = fileName.toStdString();
		cv::imwrite(filename, image);
	}
}