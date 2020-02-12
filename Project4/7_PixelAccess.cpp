//image.at을 사용해서 pixels에 access

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

int main() {
	Mat image, image_gray;
	int value, value_B, value_G, value_R, channels;

	

	image = imread("Lena.png",0);
	//image_gray = imread("Lena.png", 0);

	channels = image.channels();
	
	switch (channels) {
	case 1 : //단일채널일 경우
		value = image.at<uchar>(50, 100);
		cout << "value : " << value << endl;
		break;

	case 3 :
		value_B = image.at<Vec3b>(50, 100)[0]; //(행,열)
		value_G = image.at<Vec3b>(50, 100)[1];
		value_R = image.at<Vec3b>(50, 100)[2];
		cout << "value at (100,50) : " << value_B << " " << value_G << " " << value_R << endl;
		break;

	}
	//printf("%d", channels);
	system("pause");
	//imshow("image", image);
	//waitKey(0);
	
}