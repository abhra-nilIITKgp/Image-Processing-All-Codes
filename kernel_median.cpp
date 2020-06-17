//blur through median filter of surr pixels method

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

//reading original img
Mat img=imread("/home/nil/IP/veg.jpg",0);

//calculating median of surrounding cells pixel
int median(int i,int j)
{
int med[9],k,l,pix,c=0;
//here making 3x3 kernel. If 5x5 make i-2,i+3,j-2,j+3 and divide sum by 25. Similarly for other kernels
for(k=i-1;k<i+2;k++)
{
 for(l=j-1;l<j+2;l++)
 {
  med[c]=img.at<uchar>(k,l);
  c++;
 }
}
sort(med,med+9);
return(med[4]);
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
          a.at<uchar>(i,j)=median(i,j);//assigning new pixel values to clear noise and blur out
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


