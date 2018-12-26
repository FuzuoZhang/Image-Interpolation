#include "operation.h"
#include <opencv2/core/core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace  cv;
using namespace std;
operation::operation( int style,String filename, QWidget *parent)
	:style(style),filename(filename), QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("ͼ��任"));
	initia();//��ʼ��
	 //��slider��spinbox��ֵ�仯��ʱ�򷢳�valueChanged�ź�
	//connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));
	//connect(ui.doubleSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

	connect(ui.horizontalSlider, SIGNAL(valueChanged(double)), ui.doubleSpinBox, SLOT(setValue(double)));
	connect(ui.doubleSpinBox, SIGNAL(valueChanged(double)), ui.horizontalSlider, SLOT(setValue(double)));

	connect(ui.horizontalSlider_2, SIGNAL(valueChanged(double)), ui.doubleSpinBox_2, SLOT(setValue(double)));
	connect(ui.doubleSpinBox_2, SIGNAL(valueChanged(double)), ui.horizontalSlider_2, SLOT(setValue(double)));

	connect(ui.horizontalSlider_3, SIGNAL(valueChanged(double)), ui.doubleSpinBox_3, SLOT(setValue(double)));
	connect(ui.doubleSpinBox_3, SIGNAL(valueChanged(double)), ui.horizontalSlider_3, SLOT(setValue(double)));
}


operation::~operation()
{
}

void operation::initia() {
	img = imread(filename);
	img_ope = img;
	ui.horizontalSlider->setRange(minrou,maxrou);  // rou��Χ
	ui.doubleSpinBox->setRange(minrou, maxrou);

	ui.horizontalSlider_2->setRange(minsita,maxsita);  // sita��Χ//������ʱ��Ϊsita �� fai�ķ�Χ��һ���ġ�
	ui.doubleSpinBox_2->setRange(minrou, maxrou);

	ui.horizontalSlider_3->setRange(minR,maxR);  // R��Χ
	ui.doubleSpinBox_3->setRange(minrou, maxrou);

	ui.horizontalSlider->setValue(rou);   //�趨��ʼֵ
	ui.doubleSpinBox->setValue(rou);

	ui.horizontalSlider_2->setValue(sita);
	ui.doubleSpinBox_2->setValue(sita);

	ui.horizontalSlider_3->setValue(R);
	ui.doubleSpinBox_3->setValue(R);
}
void operation::operate() {  //���ñ任����
	switch (style)
	{
	case 1: img_ope=rotation(img, R, sita, method);
		break;
	case 2: img_ope=ripple(img, R, fai, rou, method);
		break;
		//case 3:
		//break;
	default:break;
	}
}

void operation::on_pushButton_clicked() { //����ڲ�ֵ
	method = 1;
	
}

void operation::on_pushButton_2_clicked() {//˫���Բ�ֵ
	method = 2;


}

void operation::on_pushButton_3_clicked() {//˫���β�ֵ
	method = 3;
}

void operation::on_pushButton_5_clicked() {  //ȷ����ť
	R = ui.doubleSpinBox_3->value();
	sita = ui.doubleSpinBox_2->value();
	rou = ui.doubleSpinBox->value();
	operate(); 
	//��ʾͼƬ
	cv::cvtColor(img_ope, img_ope, CV_BGR2RGB);

	image = QImage((const unsigned char*)(img_ope.data), img_ope.cols, img_ope.rows, QImage::Format_RGB888);

	ui.label->setPixmap(QPixmap::fromImage(image));

	ui.label->resize(ui.label->pixmap()->size());

	ui.label->show();
}


double operation::distance(int x, int y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double operation::Arfa(int x, int y, double r)
{
	double sita = acos(x / r);
	if (y >= 0)  return sita;
	else return 2 * PI - sita;
}

double operation::bilinear(int x, int y, double u, double v, Mat img, int s)
{
	return (1 - v)*((1 - u)*(img.at<cv::Vec3b>(x, y)[s]) + u*(img.at<cv::Vec3b>(x + 1, y)[s]))
		+ v*((1 - u)*(img.at<cv::Vec3b>(x, y + 1)[s]) + u*(img.at<cv::Vec3b>(x + 1, y + 1)[s]));
}

double operation::kernel(double x)  //˫���β�ֵ�˺���
{
	double y = abs(x);
	if (y <= 1) {
		return 1 - 2 * pow(y, 2) + pow(y, 3);
	}
	else if (y > 1 && y < 2) {
		return 4 - 8 * y + 5 * pow(y, 2) - pow(y, 3);
	}
	else return 0;
}

double operation::mybicubic(int i, int j, double u, double v, Mat x, int s) //˫���β�ֵ
{
	double U[4], V[4];
	int k, t;
	for (k = 0; k < 4; k++) {
		U[k] = kernel(u + 1 - k);
		V[k] = kernel(v + 1 - k);
	}  //�ֱ��A��C ���󸳳�ֵ��
	double result = 0;
	for (k = 0; k <= 3; k++)
		for (t = 0; t <= 3; t++)
		{
			result = result + V[k] * U[t] * x.at<cv::Vec3b>(i - 1 + t, j - 1 + k)[s];
		}
	return result;
}


Mat operation::rotation(Mat img, double R, double sita, int method)
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
				if (x >= 1 && x < row - 2 && y >= 1 && y < col - 2)
				{
					int s;
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++) {
						I.at<cv::Vec3b>(i, j)[s] = mybicubic(x, y, u, v, img, s);
					}
				}
				break;
			default:break;
			}
		}
	return I;
}

Mat operation::ripple(Mat img, double R, double fai, double rou, int method)
{
	int row = img.rows;  //the rows of the image
	int col = img.cols;  //the columns of the image
	int mid_row = row / 2;
	int mid_col = col / 2;

	Mat J = img.clone();
	int i, j, s;
	double k = 0.1;
	double x_img, y_img;
	for (i = 0; i<row; i++)
		for (j = 0; j < col; j++)
		{
			int x = i - mid_row;
			int y = j - mid_col;
			double r = distance(x, y);
			if (r > R)  continue;
			double arfa = Arfa(x, y, r);
			double arfa_img = arfa - k*sin(r*rou / R + fai);
			x_img = r*cos(arfa_img) + mid_row;
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
					else  J.at<cv::Vec3b>(i, j)[s] = 0;
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
					for (s = 0; s <= 2; s++)
						J.at<cv::Vec3b>(i, j)[s] = 0;
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
						J.at<cv::Vec3b>(i, j)[s] = mybicubic(x, y, u, v, img, s);
				}
				else {
					for (s = 0; s <= 2; s++)
						J.at<cv::Vec3b>(i, j)[s] = 0;
				}
				break;
			default:break;
			}
		}
	return J;
}
