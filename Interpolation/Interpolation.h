#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Interpolation.h"
#include "mydialog.h"
#include "Bspline_Dialog.h"
#include <QFileDialog>
#include <qmessagebox.h>
class Interpolation : public QMainWindow
{
	Q_OBJECT

public:
	String imgname; //��ѡ��Ƭ
	int style=1;//ͼ��任����  //Ĭ����ת�任

	Interpolation(QWidget *parent = Q_NULLPTR);
	void Interpolation::open();  
	bool check();
public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
private:
	Ui::InterpolationClass ui;
};
