#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img1=imread("/home/nil/adadadad/rubiks.jpg",1);

int main(int argc, char const *argv[])
{
	int ang=0;
	//creating a window
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",img);
        create Trackbar("trackbar1","window1",&ang,360,callback);
	waitKey(0);	
	return 0;
}
void callback(int a,void *c)
{
 int i,j,row,col,xnew,ynew;
 row = img.rows,col = img.cols;
 float angle=a*CV_PI/100,side;

 side=(sqrt(row*row+col*col))+1;
 
 Mat img2((int)side,(int)side,CV_8UC3,Scalar(0,0,0));

 for(int i=0; i< row; i++)
 {
  for(int j=0; j< col; j++)
  {
   xnew=((i-row/2)*cos(angle)+(col/2-j)*(sin(angle))+side/2;
   ynew=((i-row/2)*sin(angle)*(-1)+(col/2-j)*(cos(angle))-side/2;
   ynew*=-1;
   for(int m=0;m<3;m++){img2.at<Vec3b>(xnew,ynew)[m]=img1.at<Vec3b>(i,j)[m];}
  }
 }
 imshow("TrackBar",img2);
}











