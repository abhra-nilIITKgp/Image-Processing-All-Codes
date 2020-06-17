//blur through mean filter of surr pixels method

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//reading original img
Mat img=imread("/home/nil/IP/lena.png",0);

//calculating average of surrounding cells pixel
int average(int i,int j)
{
int sum=0,k,l;
//here making 3x3 kernel. If 5x5 make i-2,i+3,j-2,j+3 and divide sum by 25. Similarly for other kernels
for(k=i-1;k<i+2;k++)
{
 for(l=j-1;l<j+2;l++)
 {
  sum+=img.at<uchar>(k,l);
 }
}
return(sum/9);
}

int main(int argc, char const *argv[])
{
	int i,j,r,c;
        r=img.rows;
        c=img.cols;
        Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));//to hold new image
        for(i=0;i<r;i++)
        {
         for(j=0;j<c;j++)
         {
          a.at<uchar>(i,j)=average(i,j);//assigning new pixel values to clear noise and blur out
         }
        }
	//creating a window to display
	namedWindow("kernel",WINDOW_AUTOSIZE);
        namedWindow("kernel1",WINDOW_AUTOSIZE);
	imshow("kernel",img);
        imshow("kernel1",a);
	waitKey(0);	
	return 0;
}


