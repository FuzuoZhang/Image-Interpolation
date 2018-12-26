/*
mydialog class ����������ת�任��ˮ���Ʊ任�Ĳ���ѡ�񡣱�������Interpolation ����
*/
#include "mydialog.h"
#include <opencv2\imgproc\imgproc.hpp>
using namespace  cv;
using namespace std;
mydialog::mydialog(int style, String filename,QWidget *parent)
	:style(style), Filename(filename), QDialog(parent)
{
	ui.setupUi(this);
	//setWindowTitle(QString::fromLocal8Bit("ͼ��任"));
	initia();//��ʼ��
	
	//����Ϊ΢����ͻ������ӵ��źŲ�
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)),this, SLOT(slider2spinbox()));
	connect(ui.doubleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(spinbox2slider()));

	connect(ui.horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(slider2spinbox_2()));
	connect(ui.doubleSpinBox_2, SIGNAL(valueChanged(double)), this, SLOT(spinbox2slider_2()));

	connect(ui.horizontalSlider_3, SIGNAL(valueChanged(int)), ui.SpinBox_3, SLOT(setValue(int)));
	connect(ui.SpinBox_3, SIGNAL(valueChanged(int)), ui.horizontalSlider_3, SLOT(setValue(int)));
}

mydialog::~mydialog()
{
}

void mydialog::initia() {
	
	img = cv::imread(Filename);
	img_ope = img;
	if (style == 1) maxR = 256;
	ui.horizontalSlider->setRange(minrou, maxrou);  // rou��Χ
	ui.doubleSpinBox->setRange(minrou, maxrou);
	
	ui.horizontalSlider_2->setRange(minsita, maxsita*100);  // sita��Χ//������ʱ��Ϊsita �� fai�ķ�Χ��һ���ġ�
	ui.doubleSpinBox_2->setRange(minsita, maxsita);
	ui.doubleSpinBox_2->setSingleStep(0.1);

	ui.horizontalSlider_3->setRange(minR, maxR);  // R��Χ
	ui.SpinBox_3->setRange(minR, maxR);

	ui.horizontalSlider->setValue(rou);   //�趨rou��ʼֵ
	ui.doubleSpinBox->setValue(rou);

	ui.horizontalSlider_2->setValue(sita); //�趨sita��ʼֵ
	ui.doubleSpinBox_2->setValue(sita);

	ui.horizontalSlider_3->setValue(R);  //�趨R��ʼֵ
	ui.SpinBox_3->setValue(R);
}
void mydialog::operate() {  //���ñ任����
	switch (style)
	{
	case 1: img_ope = rotation(img, R, sita, method);  //��ת����
		break;
	case 2: img_ope = ripple(img, R, fai, rou, method);//ˮ���Ʊ���
		break;
	default:break;
	}
}

void mydialog::on_pushButton_clicked() { //����ڲ�ֵ
	method = 1;
}

void mydialog::on_pushButton_2_clicked() {//˫���Բ�ֵ
	method = 2;
}

void mydialog::on_pushButton_3_clicked() {//˫���β�ֵ
	method = 3;
}

void mydialog::on_pushButton_5_clicked() {  //ȷ����ť
	R = ui.SpinBox_3->value();    //������ֵ
	sita = ui.doubleSpinBox_2->value();
	rou = ui.doubleSpinBox->value();
	operate();
	Display_Dialog * display = new Display_Dialog(img_ope);
	if (style == 1) display->setWindowTitle(QString::fromLocal8Bit("��ת�任"));
	else display->setWindowTitle(QString::fromLocal8Bit("ˮ���Ʊ任"));
	display->exec();
}

void  mydialog::spinbox2slider() {//΢�����ֵ����������
	ui.horizontalSlider->setValue((int)(ui.doubleSpinBox->value()));  
}
void  mydialog::spinbox2slider_2() {
	ui.horizontalSlider_2->setValue((int)(ui.doubleSpinBox_2->value() * 100));
}
void  mydialog::slider2spinbox() {//��������ֵ����΢����
	ui.doubleSpinBox->setValue((double)(ui.horizontalSlider->value()));
}
void  mydialog::slider2spinbox_2() {
	ui.doubleSpinBox_2->setValue((double)(ui.horizontalSlider_2->value()) / 100.0);
}

double mydialog::distance(int x, int y)//�����
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double mydialog::Arfa(int x, int y, double r)  //��Ƕ�
{
	double sita = acos(x / r);
	if (y >= 0)  return sita;
	else return 2 * PI - sita;
}

double mydialog::bilinear(int x, int y, double u, double v, Mat img, int s) //˫���Բ�ֵ
{
	return (1 - v)*((1 - u)*(img.at<cv::Vec3b>(x, y)[s]) + u*(img.at<cv::Vec3b>(x + 1, y)[s]))
		+ v*((1 - u)*(img.at<cv::Vec3b>(x, y + 1)[s]) + u*(img.at<cv::Vec3b>(x + 1, y + 1)[s]));
}

double mydialog::kernel(double x)  //˫���β�ֵ�˺���
{
	double y;
	if (x < 0) y = 0 - x;
	else y = x;
	double result;
	if (y <= 1) {
		result= 1 - 2 * y * y  + y * y * y;
	}
	if (y > 1 && y <=2) {
		result= 4 - 8 * y + 5 * y * y - y * y * y;
	}
	if(y>2) result= 0;
	return result;
}

double mydialog::mybicubic(int i, int j, double u, double v, Mat x, int s) //˫���β�ֵ
{
	double U[4], V[4];
	int k, t;
	for (k = 0; k < 4; k++) {
		U[k] = kernel(u +1 - k);
		V[k] = kernel(v +1 - k);
	}  //�ֱ��A��C ���󸳳�ֵ��
	double result = 0;
	for (k = 0; k <= 3; k++)
	{
		for (t = 0; t <= 3; t++)
		{
			result = result + V[k] * U[t] * (x.at<cv::Vec3b>(i - 1 + t, j - 1 + k)[s]);
		}
	}
	return result;
}


Mat mydialog::rotation(Mat img, double R, double sita, int method)  //��ת����  methodָ��ֵ����
{
	int row = img.rows;  //the rows of the image
	int col = img.cols;  //the columns of the image
	int mid_row = row / 2;
	int mid_col = col / 2;

	Mat I = img.clone();  //clone the image to I
	int i, j, s;
	for (i = 0; i<row; i++)
		for (j = 0; j < col; j++)
		{
			int x = i - mid_row;
			int y = j - mid_col;
			double x_img, y_img;//x_img,y_imgΪ��תͼ���ϣ�i��j���������任���õ�ԭͼ�����꣨�ܿ����Ǹ�������
			double r = distance(x, y);
			if (r > R)  continue;
			double arfa = this->Arfa(x, y, r);
			double arfa_img = arfa - sita*(R - r) / R;
			x_img = r*cos(arfa_img) + mid_row;
			y_img = r*sin(arfa_img) + mid_col;
			x = floor(x_img);
			y = floor(y_img);  //x,y ��Ϊx_img,y_img ����ȡ��������ڲ�ֵ��
			switch (method)
			{
			case 1:
				//  ����ڲ�ֵ�����ĸ�ֵ
				if (x >= 0 && x < row && y >= 0 && y < col)
				{
					for (s = 0; s <= 2; s++)
						I.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
				}
				break;

			case 2:
				//˫���Բ�ֵ�����ĸ�ֵ
				if (x >= 0 && x < row - 1 && y >= 0 && y < col - 1)
				{
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++)
					{
						I.at<cv::Vec3b>(i, j)[s] = bilinear(x, y, u, v, img, s);
					}
				}
				break;

			case 3:
				//˫���β�ֵ������ֵ
				if (x >= 1 && x < row - 3 && y >= 1 && y < col - 3)
				{
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++)
					{
						double xiangsu= mybicubic(x, y,u, v, img, s);
						if (xiangsu > 255) xiangsu = 255;
						if (xiangsu < 0) xiangsu = 0;
						I.at<cv::Vec3b>(i, j)[s] = xiangsu;
					}
				}
				break;
			default:break;
			}
		}
	return I;
}

Mat mydialog::ripple(Mat img, double R, double fai, double rou, int method)//ˮ���ƺ���
{
	int row = img.rows;  //the rows of the image
	int col = img.cols;  //the columns of the image
	int mid_row = row / 2;
	int mid_col = col / 2;

	Mat J = img.clone();
	int i, j, s;
	double k = 0.1;
	double x_img, y_img;
	for (i = 0; i<row; i++)  //��ÿ���㸳ֵ
		for (j = 0; j < col; j++)
		{
			int x = i - mid_row;
			int y = j - mid_col;
			double r = distance(x, y);
			if (r > R)  continue;
			double arfa = Arfa(x, y, r);
			double arfa_img = arfa - k*sin(r*rou / R + fai);  //��ԭͼ������Ӧ�ĽǶ�
			x_img = r*cos(arfa_img) + mid_row; //ԭͼ�е�����
			y_img = r*sin(arfa_img) + mid_col;
			x = (int)x_img;
			y = (int)y_img;
			switch (method)
			{
			case 1:            //����ڲ�ֵ
				for (s = 0; s <= 2; s++)
				{
					if (x >= 0 && x < row && y >= 0 && y < col)
						J.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
					else {//������ͼƬ��Χ�ڣ�ȡ��Ե
						if (x >= row) x = row - 1;
						if (x < 0)    x = 0;
						if (y >= col) y = col - 1;
						if (y < 0)    y = 0;
						J.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
					}
				}
				break;
			case 2:
				//˫���Բ�ֵ
				if (x >= 0 && x < row - 1 && y >= 0 && y < col - 1)
				{
					int s;
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++)
						J.at<cv::Vec3b>(i, j)[s] = bilinear(x, y, u, v, img, s);
				}
				else {
					if (x >= row) x = row - 1;  //������ͼƬ��Χ�ڣ�ȡ��Ե
					if (x < 0)    x = 0;
					if (y >= col) y = col - 1;
					if (y < 0)    y = 0;
					for (s = 0; s <= 2; s++)
						J.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
				}
				break;
			case 3:
				//˫���β�ֵ
				if (x >= 1 && x < row - 2 && y >= 1 && y < col - 2)
				{
					int s;
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++)
					{
						double xiangsu = mybicubic(x, y, u, v, img, s);  
						if (xiangsu > 255) xiangsu = 255;//��ֹԽ��
						if (xiangsu < 0) xiangsu = 0;
						J.at<cv::Vec3b>(i, j)[s] = xiangsu;
					}
				}
				else {//������ͼƬ��Χ�ڣ�ȡ��Ե
					if (x >= row) x = row - 1;
					if (x < 0)    x = 0;
					if (y >= col) y = col - 1;
					if (y < 0)    y = 0;
					for (s = 0; s <= 2; s++)
						J.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
				}
				break;
			default:break;
			}
		}
	return J;
}
