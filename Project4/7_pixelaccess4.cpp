// pixel access using MatIterator

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	Mat image = imread("Lena.png");
	int value, value_B, value_G, value_R, channels;
	channels = image.channels();


	//using MatIterator
	MatIterator_ <uchar> it, end;
	MatIterator_ <Vec3b> it3, end3;

	switch (channels) {
	case 1:
		for (it = image.begin<uchar>(), end = image.end<uchar>(); it != end; it++) { //이미지의 모든 픽셀의 밝기 출력
			value = *it;
			cout << "value = " << value << endl;
		}
		break;

	case 3:
		for (it3 = image.begin<Vec3b>(), end3 = image.end<Vec3b>(); it3 != end3; it3++) { //이미지의 모든 픽셀의 RGB출력
			value_B = (*it3)[0];
			value_G = (*it3)[1];
			value_R = (*it3)[2]; // *it3[2] 가 아닌 (*it)[2]라고 해야한다. it 자체가 채널 array 묶음을 가리키는 인자 이기때문
			cout << "values = " << value_B << ", " << value_G << ", " << value_R << endl;
		}
		break;
	}

	waitKey(0);
	system("pause");
}