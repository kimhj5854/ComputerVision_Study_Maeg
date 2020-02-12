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
		for (it = image.begin<uchar>(), end = image.end<uchar>(); it != end; it++) { //�̹����� ��� �ȼ��� ��� ���
			value = *it;
			cout << "value = " << value << endl;
		}
		break;

	case 3:
		for (it3 = image.begin<Vec3b>(), end3 = image.end<Vec3b>(); it3 != end3; it3++) { //�̹����� ��� �ȼ��� RGB���
			value_B = (*it3)[0];
			value_G = (*it3)[1];
			value_R = (*it3)[2]; // *it3[2] �� �ƴ� (*it)[2]��� �ؾ��Ѵ�. it ��ü�� ä�� array ������ ����Ű�� ���� �̱⶧��
			cout << "values = " << value_B << ", " << value_G << ", " << value_R << endl;
		}
		break;
	}

	waitKey(0);
	system("pause");
}