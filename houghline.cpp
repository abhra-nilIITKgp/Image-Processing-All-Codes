#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
Mat img=imread("/home/nil/IP/samps/A1.png",0);
int find_r(int x,int y,float ang)
{
	int r;
	r=x*cos(ang)+y*sin(ang);
}
int main(int argc, char const *argv[])
{
	int i,j,row,col,r,c,x,y,ang,size;

	row=img.rows;
	col=img.cols;
	size=sqrt(row*row+col*col);
	Mat img1(2*size+1,180,CV_8UC1,Scalar(0));
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(img.at<uchar>(i,j)==255)
			{
				x=j;
				y=row-i;
				for(ang=1;ang<=180;ang++)
				{
					r=find_r(x,y,(CV_PI*ang/180.0));
					img1.at<uchar>(size-r,ang)+=5;
				}
			}
		}
	}
	resize(img1,img1,Size(2*size+1,1800));
	namedWindow("curve",WINDOW_NORMAL);
	imshow("curve",img1);
	waitKey(0);	
	return 0;
	
}
