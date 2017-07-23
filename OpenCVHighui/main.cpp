#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	//��ȡͼ��
	Mat p1 = imread("./p1.jpg");
	Mat p2 = imread("./p2.jpg");
	
	//��������
	namedWindow("P1", WINDOW_AUTOSIZE);
	namedWindow("P2", WINDOW_AUTOSIZE);

	//�ƶ�����
	moveWindow("P1", 10,10);
	moveWindow("P2", 520, 10);

	//չʾͼ��
	imshow("P1", p1);
	imshow("P2", p2);

	//�������ڴ�С����������ʹ��ģʽʱ
	resizeWindow("P1", 512, 512);

	//�ȴ���������
	waitKey(0);

	//���ٴ���
	destroyWindow("P1");
	destroyWindow("P2");

	//����10���´���
	for (int i = 0; i < 3; i++)
	{
		ostringstream ss;
		ss << "Photo" << i;
		namedWindow(ss.str());
		moveWindow(ss.str(), 20 * i, 20 * i);
		imshow(ss.str(), p2);
	}
	//�ȴ���������
	waitKey(0);
	//�������д���
	destroyAllWindows();
	return 0;
}