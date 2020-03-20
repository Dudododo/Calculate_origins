#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat scrMat = imread("IMG_1989.JPG", 0);
	cv::Mat dstMat,outMat, statsMat, centrMat;
	imshow("scrMat", scrMat);

	threshold(scrMat, dstMat, 30, 255, THRESH_BINARY_INV);
	
	cv::Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(12,12));	

	//腐蚀
	morphologyEx(dstMat, dstMat, MORPH_ERODE, kernel);

	int nComp = connectedComponentsWithStats(dstMat, outMat, statsMat, centrMat, 8, CV_32S);
	cout << "the number of origins = " << nComp - 1 << endl;

	imshow("dstMat", dstMat);

	waitKey(0);
	return 0;
}

