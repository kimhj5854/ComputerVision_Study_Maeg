// Mat �� pointer �� ����ؼ� pixel access

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	Mat image = imread("Lena.png");
	int value, value_B, value_G, value_R, channels;
	channels = image.channels();


	//pointer
	uchar *p;
	p = image.ptr<uchar>(50); //50��° �࿡ ���� �����Ѵ�.
	value_B = p[100 * channels + 0]; //p�� uchar�������̹Ƿ� 100�� ä�μ� channels�� �����־�� �Ѵ�.
	value_G = p[100 * channels + 1]; //channels�� �������� ������ ������ ���� �д´�.
	value_R = p[100 * channels + 2];

	cout << "B = " << value_B << "  G = " << value_G << "  R = " << value_R << endl;
	waitKey(0);
}