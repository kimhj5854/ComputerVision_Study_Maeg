// data member function�� �̿��� pixel access

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	Mat image = imread("Lena.png");
	int value, value_B, value_G, value_R, channels;
	channels = image.channels();


	//using data member function
	uchar * data = image.data;
	value_B = data[(50 * image.cols + 100) * channels + 0]; //p�� uchar�������̹Ƿ� 100�� ä�μ� channels�� �����־�� �Ѵ�.
	value_G = data[(50 * image.cols + 100) * channels + 1]; //channels�� �������� ������ ������ ���� �д´�.
	value_R = data[(50 * image.cols + 100) * channels + 2];

	cout << "B = " << value_B << "  G = " << value_G << "  R = " << value_R << endl;
	waitKey(0);
	system("pause");
}