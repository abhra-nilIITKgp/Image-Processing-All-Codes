#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>

using namespace cv;
using namespace std;

int main()

{

  Mat img=imread("/home/nil/adadadad/rubiks.jpg",1);
  int nc= img.cols;
  int nr=img.rows;
  Mat img1((int)nr/2,(int)nc/2,CV_8UC3,Scalar(0,0,0));
  for(int y=0;y<nr/2;y++)
  {

   for(int x=0;x<nc/2;x++)
   {

   img1.at<Vec3b>(y,x)[0]=(img.at<Vec3b>(2*y,2*x)[0]+img.at<Vec3b>(2*y+1,2*x)[0]+img.at<Vec3b>(2*y+1,2*x+1)[0]+img.at<Vec3b>(2*y,2*x+1)[0])/4;

  img1.at<Vec3b>(y,x)[1]=(img.at<Vec3b>(2*y,2*x)[1]+img.at<Vec3b>(2*y+1,2*x)[1]+img.at<Vec3b>(2*y+1,2*x+1)[1]+img.at<Vec3b>(2*y,2*x+1)[1])/4; 

   img1.at<Vec3b>(y,x)[2]=(img.at<Vec3b>(2*y,2*x)[2]+img.at<Vec3b>(2*y+1,2*x)[2]+img.at<Vec3b>(2*y+1,2*x+1)[2]+img.at<Vec3b>(2*y,2*x+1)[2])/4;

   }

  }

   namedWindow("waste",WINDOW_AUTOSIZE);

   imshow("waste",img1);

   waitKey(0);

   return 0;

} 
