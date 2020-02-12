// Mat 의 pointer 를 사용해서 pixel access

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
	p = image.ptr<uchar>(50); //50번째 행에 먼저 접근한다.
	value_B = p[100 * channels + 0]; //p가 uchar포인터이므로 100에 채널수 channels를 곱해주어야 한다.
	value_G = p[100 * channels + 1]; //channels를 곱해주지 않으면 엉뚱한 값을 읽는다.
	value_R = p[100 * channels + 2];

	cout << "B = " << value_B << "  G = " << value_G << "  R = " << value_R << endl;
	waitKey(0);
}