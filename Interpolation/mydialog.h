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
	double maxR = 400;  //������Χֵ
	double minR = 1;
	double maxsita = 2 * PI;
	double minsita = 0;
	double maxfai = 2 * PI;
	double minfai = 0;
	double maxrou = 100;
	double minrou = 0;
	String Filename;
	Mat img; //ԭͼ����
	Mat img_ope; //�任���ͼ�����
	QImage image;
	double R = 2;   //���β���
	double sita = 0;
	double fai = 0;
	double rou = 0;
	int style;  //�任����
	int method = 1; //��ֵ����(Ĭ������ڣ�
private:
	void operate();
	double distance(int x, int y);
	double Arfa(int x, int y, double r);
	double bilinear(int x, int y, double u, double v, Mat img, int s);
	double kernel(double x); //˫���β�ֵ�˺���
	double mybicubic(int i, int j, double u, double v, Mat x, int s); //˫���β�ֵ
	Mat rotation(Mat img, double R, double sita, int method);
	Mat ripple(Mat img, double R, double fai, double rou, int method);
	Ui::mydialog ui;
};
