

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

//reading original img
Mat img1=imread("/home/nil/IP/erosion.png",0);
Mat img2=imread("/home/nil/IP/erosion2.png",0);
Mat img3=imread("/home/nil/IP/erosion3.png",0);
Mat img4=imread("/home/nil/IP/erosion4.png",0);
//erosion to remove white noise
int erosion(Mat img,int i,int j)
{
int k,l;
//here making 3x3 kernel. If 5x5 make i-2,i+3,j-2,j+3 and divide sum by 25. Similarly for other kernels
for(k=i-1;k<i+2;k++)
{
 for(l=j-1;l<j+2;l++)
 {
  if(img.at<uchar>(k,l)==0)
   return 0;
 }
}
 return 255;
}


//dilation to remove black noise
int dilation(Mat img,int i,int j)
{
int k,l;
//here making 3x3 kernel. If 5x5 make i-2,i+3,j-2,j+3 and divide sum by 25. Similarly for other kernels
for(k=i-1;k<i+2;k++)
{
 for(l=j-1;l<j+2;l++)
 {
  if(img.at<uchar>(k,l)==255)
   return 255;
 }
}
 return 0;
}


int main(int argc, char const *argv[])
{
	int i,j,r,c;
        r=img2.rows;
        c=img2.cols;
        Mat a(img2.rows,img2.cols,CV_8UC1,Scalar(0));//to hold new image
        Mat b(img2.rows,img2.cols,CV_8UC1,Scalar(0));
        for(i=0;i<r;i++)
        {
         for(j=0;j<c;j++)
         {
          a.at<uchar>(i,j)=dilation(img2,i,j);//assigning new pixel values to clear noise and blur out
         }
        }

        for(i=0;i<r;i++)
        {
         for(j=0;j<c;j++)
         {
          b.at<uchar>(i,j)=erosion(a,i,j);//assigning new pixel values to clear noise and blur out
         }
        }

	//creating a window to display
	namedWindow("kernel",WINDOW_AUTOSIZE);
        namedWindow("kernel1",WINDOW_AUTOSIZE);
	imshow("kernel",img2);
        imshow("kernel1",a);
        imshow("kernel2",b);
	waitKey(0);	
	return 0;
}


