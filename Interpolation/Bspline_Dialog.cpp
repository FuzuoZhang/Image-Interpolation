/*
Bspline_Dialog class ������ͼ���ϵĿ��Ƶ�����϶��Լ���ֵ������ѡ��
*/
#include "Bspline_Dialog.h"
#include <opencv2\imgproc\imgproc.hpp>
Bspline_Dialog::Bspline_Dialog(String filename,QWidget *parent)
	: Filename(filename), QDialog (parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("B��������"));
	this->setMouseTracking(true);
	ui.label->setMouseTracking(true);
	inita(); //��ʼ������
	cv::cvtColor(img_ope, img_ope, CV_BGR2RGB);  //��ʾԭͼƬ
	image = QImage((const unsigned char*)(img_ope.data), img_ope.cols, img_ope.rows, QImage::Format_RGB888);
	ui.label->setPixmap(QPixmap::fromImage(image));
	ui.label->resize(ui.label->pixmap()->size());
	int i, j;
	for (i = 0; i<3; i++)  //��ʼ�����Ƶ�λ��
		for (j = 0; j < 3; j++)
		{
			p[i][j][0] = 127 * (j + 1) + j;
			p[i][j][1] = 127 * (i + 1) + i;
		}	
}

Bspline_Dialog::~Bspline_Dialog()
{
}
void Bspline_Dialog::inita() {   //��ʼ������
	img = cv::imread(Filename);
	deltap[3][3][2] = { 0 };
	img_ope = img;
}
bool Bspline_Dialog::check_area()  //��鵱ǰ������ڵ�λ��
{
	int i, j;
	for (i = 0; i<3; i++)
		for (j = 0; j < 3; j++)
		{
			if (abs(pos_move.x() - p[i][j][0]) < 20 && abs(pos_move.y() - p[i][j][1]) < 20)
			{
				px = i;
				py = j;
				return true;
			}
		}
	return false;
}

void Bspline_Dialog::mouseMoveEvent(QMouseEvent *event)  //����ƶ��Ĳۺ�����������λ�ò�����ֵ������������������
{
	if (mark==0){
		int xoffset = (ui.label->contentsRect().width() - ui.label->pixmap()->rect().width()) / 2;
		int yoffset = (ui.label->contentsRect().height() - ui.label->pixmap()->rect().height()) / 2;
		pos_move.setX(ui.label->mapFromGlobal(event->globalPos()).x() - xoffset);
		pos_move.setY(ui.label->mapFromGlobal(event->globalPos()).y() - yoffset);
		if (check_area()) {
			setCursor(Qt::CrossCursor);
		}
		else setCursor(Qt::ArrowCursor);
	}
}
void Bspline_Dialog::mousePressEvent(QMouseEvent *event) //������Ĳۺ���
{
	if (event->button() == Qt::LeftButton)
	{
		if(check_area()&&mark==0)//�ڿ��Ƶ����������
		{
			pos_press.setX(pos_move.x()); //��¼�������λ��
			pos_press.setY(pos_move.y());
			mark = 1;
		}
	}
}

void Bspline_Dialog::mouseReleaseEvent(QMouseEvent *event)  //����ͷŵĲۺ���  ��¼��ǰλ�ã�������Ƶ��ƶ��ľ���
{
	if (mark == 1) {
		int xoffset = (ui.label->contentsRect().width() - ui.label->pixmap()->rect().width()) / 2;
		int yoffset = (ui.label->contentsRect().height() - ui.label->pixmap()->rect().height()) / 2;
		pos_release.setX(ui.label->mapFromGlobal(event->globalPos()).x() - xoffset);
		pos_release.setY(ui.label->mapFromGlobal(event->globalPos()).y() - yoffset);
		if (pos_release.x() < 0) pos_release.setX(0);
		if (pos_release.y() < 0) pos_release.setY(0);
		if (pos_release.x() >= img.rows) pos_release.setX(img.rows - 1);
		if (pos_release.y() >= img.cols) pos_release.setY(img.cols - 1);
		deltap[px][py][1] =p[px][py][0]- pos_release.x();
		deltap[px][py][0] =p[px][py][1] - pos_release.y();
		mark = 0;
		px = 0; py = 0;

	}
}

void Bspline_Dialog::on_pushButton_clicked() {  //ȷ����
	img = imread(Filename);
	img_ope = Bspline(img, deltap, method);
	Display_Dialog * display = new Display_Dialog(img_ope);
	display->setWindowTitle(QString::fromLocal8Bit("B��������"));
	display->exec();
	inita();
}
void Bspline_Dialog::on_pushButton_3_clicked() {
	method = 1;   //����ڲ�ֵ
}
void Bspline_Dialog::on_pushButton_4_clicked() {
	method = 2;  //˫���Բ�ֵ 
}
void Bspline_Dialog::on_pushButton_5_clicked() {
	method = 3;  //˫���β�ֵ
}

Mat Bspline_Dialog::Bspline(Mat img, int deltap[3][3][2], int method)   //B������ֵ�����صõ���ͼƬ����
{
	int row = img.rows;  //the rows of the image
	int col = img.cols;  //the columns of the image
	int mid_row = row / 2;
	int mid_col = col / 2;
	Mat B = img.clone();  //��¡ԭͼ�����ڷű��κ��ͼ
	int Nx = 127;  //���Ƶ���
	int Ny = 127;
	int i, j;
	for (i = 0; i < row; i++)  //��ÿ�����ص���и�ֵ
		for (j = 0; j < col; j++)
		{
			double vx = 0;
			double vy = 0;
			double u = t_xy(i, Nx);
			double v = t_xy(j, Ny);
			int ii = floor(i / Nx)-2 ;
			int jj = floor(j / Ny)-2;
			vector<double> Gu(4);
			vector<double> Gv(4);
			Gu[0] = G03(u);  //��������ֵ�����ڵ���
			Gu[1] = G13(u);
			Gu[2] = G23(u);
			Gu[3] = G33(u);
			Gv[0] = G03(v);
			Gv[1] = G13(v);
			Gv[2] = G23(v);
			Gv[3] = G33(v);

			for (int l = 0; l <= 3; l++)   //����������ƫ��λ��
				for (int m = 0; m <= 3; m++)
				{
					if (ii + l >= 0 && ii + l < 3 && jj + m >= 0 && jj + m < 3)
					{
						if (deltap[ii + l][jj + m][0] != 0)
							vx = vx + Gu[l] * Gv[m] * deltap[ii + l][jj + m][0];
						if (deltap[ii + l][jj + m][1] != 0)
							vy = vy + Gu[l] * Gv[m] * deltap[ii + l][jj + m][1];
					}
				}
			double x_img = i + vx;
			double y_img = j + vy;
			int x, y, s;
			x = (int)x_img;
			y = (int)y_img;
			switch (method)
			{
			case 1:            //����ڲ�ֵ
				for (s = 0; s <= 2; s++)
				{
					if (x >= 0 && x < row && y >= 0 && y < col)
						B.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
					else
					{
						if (x >= row) x = row - 1;
						if (x < 0)    x = 0;
						if (y >= col) y = col - 1;
						if (y < 0)    y = 0;
						B.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
					}
				}
					break;
			case 2:
				//˫���Բ�ֵ
				if (x >= 0 && x < row - 1 && y >= 0 && y < col - 1)
				{
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++)
						B.at<cv::Vec3b>(i, j)[s] = bilinear(x, y, u, v, img, s);
				}
				else {
					if (x >= row) x = row - 1;
					if (x < 0)    x = 0;
					if (y >= col) y = col - 1;
					if (y < 0)    y = 0;
					for (s = 0; s <= 2; s++)
						B.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
				     }
				break;
			case 3:
				//˫���β�ֵ
				if (x >= 2 && x < row - 2 && y >= 2 && y < col - 2)
				{
					int s;
					double u = x_img - x;   //u,vΪ��0��1���ĸ�����
					double v = y_img - y;
					for (s = 0; s <= 2; s++)
					{
						double xiangsu = mybicubic(x, y, u, v, img, s);
						if (xiangsu > 255) xiangsu = 255;  //��ֹ����ֵ����Χ
						if (xiangsu < 0) xiangsu = 0;
						B.at<cv::Vec3b>(i, j)[s] = xiangsu;
					}
				}
				else {//������ͼƬ��Χ�ڣ�ȡ��Ե
					if (x >= row) x = row - 1;
					if (x < 0)    x = 0;
					if (y >= col) y = col - 1;
					if (y < 0)    y = 0;
					for (s = 0; s <= 2; s++)
						B.at<cv::Vec3b>(i, j)[s] = img.at<cv::Vec3b>(x, y)[s];
				      }
				break;
			default:break;
				}
			}
	return B;
}
	

double Bspline_Dialog::G03(double t)  //������
{
	return (1.0 / 6) * (-pow(t, 3) + 3 * pow(t, 2) - 3 * t + 1);
}

double Bspline_Dialog::G13(double t)
{
	return 1.0 / 6 * (3 * pow(t, 3) - 6 * pow(t, 2) + 4);
}

double Bspline_Dialog::G23(double t)
{
	return 1.0 / 6 * (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1);
}

double Bspline_Dialog::G33(double t)
{
	return 1.0 / 6 * pow(t, 3);
}

double Bspline_Dialog::t_xy(double x, double Nx)  //��t
{
	return ((x / Nx) - floor(x / Nx));
}

double Bspline_Dialog::bilinear(int x, int y, double u, double v, Mat img, int s) //˫���Բ�ֵ
{
	return (1 - v)*((1 - u)*(img.at<cv::Vec3b>(x, y)[s]) + u*(img.at<cv::Vec3b>(x + 1, y)[s]))
		+ v*((1 - u)*(img.at<cv::Vec3b>(x, y + 1)[s]) + u*(img.at<cv::Vec3b>(x + 1, y + 1)[s]));
}

double Bspline_Dialog::kernel(double x)  //˫���β�ֵ�˺���
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

double Bspline_Dialog::mybicubic(int i, int j, double u, double v, Mat x, int s) //˫���β�ֵ
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
