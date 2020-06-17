#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//Refer to opencv documentation
int main(int argc, char const *argv[])
{

	
        Mat img=imread("/home/nil/adadadad/fruits.png",1);
        int r=img.rows;
        int c=img.cols;
	Mat a(r,c,CV_8UC1,Scalar(0));
        
        for(int i=0;i<r;i++)
        {
         for(int j=0;j<c;j++)
         { 
          int xB= img.at<Vec3b>(i,j)[0];
          int xG= img.at<Vec3b>(i,j)[1];
          int xR= img.at<Vec3b>(i,j)[2];
          int x=(0.21*xG+0.72*xB+0.07*xR);
          a.at<Vec3b>(i,j)=x;
         }
        }

	//creating a window
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",a);
	waitKey(0);	
	return 0;
}
