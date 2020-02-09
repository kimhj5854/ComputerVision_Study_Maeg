#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

void pixelaccess_using_at(Mat image) {
	int channels = image.channels();
	int value, value_B, value_G, value_R;

	switch (channels) {
		case 1: //단일채널일 경우
		value = image.at<uchar>(50, 100);
		cout << "value : " << value << endl;
		break;
		
		case 3:
		value_B = image.at<Vec3b>(50, 100)[0]; //(행,열)
		value_G = image.at<Vec3b>(50, 100)[1];
		value_R = image.at<Vec3b>(50, 100)[2];
		cout << "value at (100,50) : " << value_B << " " << value_G << " " << value_R << endl;
		break;

	}
	waitKey(0);
}


int main() {
	Mat image, image_gray;
	int value, value_B, value_G, value_R, channels;


	image = imread("lena.png");
	image_gray = imread("lena.png", 0);

	pixelaccess_using_at(image);
	pixelaccess_using_at(image_gray);

	

}