#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	//读取图像
	Mat p1 = imread("./p1.jpg");
	Mat p2 = imread("./p2.jpg");
	
	//创建窗口
	namedWindow("P1", WINDOW_AUTOSIZE);
	namedWindow("P2", WINDOW_AUTOSIZE);

	//移动窗口
	moveWindow("P1", 10,10);
	moveWindow("P2", 520, 10);

	//展示图像
	imshow("P1", p1);
	imshow("P2", p2);

	//调整窗口大小，仅当非自使用模式时
	resizeWindow("P1", 512, 512);

	//等待按键按下
	waitKey(0);

	//销毁窗口
	destroyWindow("P1");
	destroyWindow("P2");

	//创建10个新窗口
	for (int i = 0; i < 3; i++)
	{
		ostringstream ss;
		ss << "Photo" << i;
		namedWindow(ss.str());
		moveWindow(ss.str(), 20 * i, 20 * i);
		imshow(ss.str(), p2);
	}
	//等待按键按下
	waitKey(0);
	//销毁所有窗口
	destroyAllWindows();
	return 0;
}