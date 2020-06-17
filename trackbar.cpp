#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

Mat a;

void call(int th, void *c)
{

	Mat f(a.rows, a.cols, CV_8UC1);

	for(int i = 0; i < a.rows; i++)
	{
		for(int j = 0; j < a.cols; j++)
		{
			if(a.at<uchar>(i,j) < th)
			{
				f.at<uchar>(i,j) = 0;
			}
			else
			{
				f.at<uchar>(i,j) = 255;
			}
		}
	}
	

	imshow("BW",f);	
}

//Refer to opencv documentation
int main(int argc, char const *argv[])
{
	int th = 127;
	//Mat image creation

	a = imread("samps/fruits.png",0);	

	namedWindow("BW",WINDOW_NORMAL);

	createTrackbar("threshold", "BW", &th, 255, call);
	

	waitKey(0);	
	return 0;
}
