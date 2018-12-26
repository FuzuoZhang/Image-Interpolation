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
	bool check_area();  //�������Ƿ�����˿��Ƶ�����
	Mat Bspline(Mat img, int deltap[3][3][2], int method);
	void inita();
	double G03(double t);
	double G13(double t);
	double G23(double t);
	double G33(double t);
	double t_xy(double x, double Nx);
	double bilinear(int x, int y, double u, double v, Mat img, int s);
	double kernel(double x); //˫���β�ֵ�˺���
	double mybicubic(int i, int j, double u, double v, Mat x, int s); //˫���β�ֵ
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
	Mat img; //ԭͼ����
	Mat img_ope; //�任���ͼ�����
	int deltap[3][3][2] = { 0 };  //���Ƶ�仯��¼����ʼΪ0.
	int p[3][3][2];   //���Ƶ�ԭλ��
	int px=0, py=0;  //���ɨ�����������Ŀ��Ƶ�
	int mark=0;//��¼��ʱ�Ƿ��ڶ�ͼƬ���п��Ƶ��ƶ�����ʼΪ0��
	int method=1;
	QImage image;  //ԭͼ��
	QImage image_ope;
	QPainter *paint;
	QPoint pos_press;
	QPoint pos_release;
	QPoint pos_move;
	bool StartEnd;
	Ui::Bspline_Dialog ui;
};
