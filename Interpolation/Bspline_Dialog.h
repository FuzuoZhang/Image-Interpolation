#pragma once

#include <QDialog>
#include "ui_Bspline_Dialog.h"
#include "Display_Dialog.h"
#include <qboxlayout.h>
#include <QFileDialog>
#include <QMouseEvent>
#include <qmessagebox.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace  cv;
using namespace std;
class Bspline_Dialog : public QDialog
{
	Q_OBJECT

public:
	Bspline_Dialog( String filename,QWidget *parent = Q_NULLPTR);
	~Bspline_Dialog();
	bool check_area();  //检查鼠标是否进入了控制点区域；
	Mat Bspline(Mat img, int deltap[3][3][2], int method);
	void inita();
	double G03(double t);
	double G13(double t);
	double G23(double t);
	double G33(double t);
	double t_xy(double x, double Nx);
	double bilinear(int x, int y, double u, double v, Mat img, int s);
	double kernel(double x); //双三次插值核函数
	double mybicubic(int i, int j, double u, double v, Mat x, int s); //双三次插值
public slots:
    void  on_pushButton_clicked();
	void  on_pushButton_3_clicked();
	void  on_pushButton_4_clicked();
	void  on_pushButton_5_clicked();
protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	//void paintEvent(QPaintEvent *event);
	
private:
	String Filename;
	Mat img; //原图矩阵；
	Mat img_ope; //变换后的图像矩阵。
	int deltap[3][3][2] = { 0 };  //控制点变化记录，初始为0.
	int p[3][3][2];   //控制点原位置
	int px=0, py=0;  //鼠标扫描过程中最近的控制点
	int mark=0;//记录此时是否在对图片进行控制点移动；初始为0；
	int method=1;
	QImage image;  //原图；
	QImage image_ope;
	QPainter *paint;
	QPoint pos_press;
	QPoint pos_release;
	QPoint pos_move;
	bool StartEnd;
	Ui::Bspline_Dialog ui;
};
