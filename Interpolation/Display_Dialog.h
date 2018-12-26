#pragma once

#include <QDialog>
#include <QFileDialog>
#include <qmessagebox.h>
#include <qboxlayout.h>
#include "ui_Display_Dialog.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace  cv;
using namespace std;
class Display_Dialog : public QDialog
{
	Q_OBJECT

public:
	Display_Dialog(Mat image,QWidget *parent = Q_NULLPTR);
	~Display_Dialog();
	public slots:
	void  on_pushButton_clicked();
private:
	Mat image;
	QImage qimage;
	Ui::Display_Dialog ui;
};
