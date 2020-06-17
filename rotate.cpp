#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;
Mat img=imread("/home/nil/IP/fruits.png",1);
//Refer to opencv documentation
void callback(int ang,void *c)
{
	int i,j,row,col,s,X,Y,x,y;
	float ang_rad;
	row=img.rows;
	col=img.cols;
	s=sqrt(row*row+col*col);
	ang_rad=(ang/180)*CV_PI;
	Mat img1(s,s,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			X=(j-col/2);
			Y=(row/2-i);
			x=X*cos(ang)-Y*sin(ang_rad) + sqrt(row*row+col*col)/2;
			y=sqrt(row*row+col*col)/2 - X*sin(ang)+Y*cos(ang_rad);
			img1.at<Vec3b>(x,y)=img.at<Vec3b>(i,j);
		}
	}
	imshow("rotate",img1);
	
	
}
int main(int argc, char const *argv[])
{	
	int ang=100;
	namedWindow("rotate",WINDOW_NORMAL);
	createTrackbar("def1","rotate",&ang,360,callback);
	
	waitKey(0);	
	return 0;
}
