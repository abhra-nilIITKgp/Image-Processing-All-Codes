#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("/home/nil/adadadad/rubiks.jpg",0);
Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
int main(int argc, char const *argv[])
{
	int th=127;
	//creating a window
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",img);
        create Trackbar("trackbar1","window1",&th,255,callback);
	waitKey(0);	
	return 0;
}
void callback(int th,void *c)
{
 int x = img.rows, y = img.cols;
 for(int i=0; i< x; i++)
 {
  for(int j=0; j< y; j++)
  {
   if(img.at<uchar>(i,j)[0]>th)
    a.at<uchar>(j,i)=255;
   else 
    a.at<uchar>(j,i)=0;
   }
 }
 imshow("a");
}
