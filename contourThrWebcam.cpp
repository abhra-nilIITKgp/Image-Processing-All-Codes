#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/core/core.hpp"

#include <iostream>

using namespace cv;

using namespace std;

 
Mat frame;

 VideoCapture vid(0);

int main()

{

 int i,j;


 while(1){

vid>>frame;
Mat a(frame.rows,frame.cols,CV_8UC1,Scalar(0));
for(int i=0; i<frame.rows;i++){
for(int j=0; j<frame.cols;j++){
if(frame.at<Vec3b>(i,j)[0]>=0 &&frame.at<Vec3b>(i,j)[0]<=131&&frame.at<Vec3b>(i,j)[1]>=0 &&frame.at<Vec3b>(i,j)[1]<=83 &&frame.at<Vec3b>(i,j)[2]>=120 &&frame.at<Vec3b>(i,j)[2]<=255)
frame.at<Vec3b>(i,j)={255,255,255};
else
frame.at<Vec3b>(i,j)={0,0,0};
}
}

Canny(frame,a,388,388*3,3);

imshow("window1" ,a);
waitKey(50);
}
destroyAllWindows();
  return 0;
}

 
