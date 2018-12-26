#pragma once
#include <QDialog>
#include <qboxlayout.h>
#include <qmessagebox.h>
#include "Display_Dialog.h"
#include "ui_mydialog.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace  cv;
using namespace std;
#define PI 3.14159265 
class mydialog : public QDialog
{
	Q_OBJECT

public:
	mydialog(int style, String filename,QWidget *parent = Q_NULLPTR);
	~mydialog();
	void initia();
	public slots:
	void spinbox2slider();
	void spinbox2slider_2();
	void slider2spinbox();
	void slider2spinbox_2();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_5_clicked();
private:
	double maxR = 400;  //参数范围值
	double minR = 1;
	double maxsita = 2 * PI;
	double minsita = 0;
	double maxfai = 2 * PI;
	double minfai = 0;
	double maxrou = 100;
	double minrou = 0;
	String Filename;
	Mat img; //原图矩阵；
	Mat img_ope; //变换后的图像矩阵。
	QImage image;
	double R = 2;   //变形参数
	double sita = 0;
	double fai = 0;
	double rou = 0;
	int style;  //变换类型
	int method = 1; //插值方法(默认最近邻）
private:
	void operate();
	double distance(int x, int y);
	double Arfa(int x, int y, double r);
	double bilinear(int x, int y, double u, double v, Mat img, int s);
	double kernel(double x); //双三次插值核函数
	double mybicubic(int i, int j, double u, double v, Mat x, int s); //双三次插值
	Mat rotation(Mat img, double R, double sita, int method);
	Mat ripple(Mat img, double R, double fai, double rou, int method);
	Ui::mydialog ui;
};
