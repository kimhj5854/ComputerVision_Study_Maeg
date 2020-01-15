//To commit, i wrote this
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image, image_YUV, merge_YUV;
	vector<Mat> yuv_channels;

	image = imread("Lena.png");
	cvtColor(image, image_YUV,COLOR_BGR2YUV);
	imshow("RGE", image);
	imshow("YUV",image_YUV);
	
	split(image_YUV, yuv_channels);
	merge(yuv_channels, merge_YUV);
	imshow("RGE", image);
	imshow("YUV", image_YUV);
	imshow("merge_YUV", merge_YUV);
	
	waitKey(0);
	

	return 0;

}