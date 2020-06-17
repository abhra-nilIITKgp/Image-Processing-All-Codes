#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace cv;
using namespace std;

int main()

{

   Mat img=imread("/home/nil/IP/fruits.png",0);
   int nc= img.cols;
   int nr=img.rows;

   int arr[256];
   for(int i=0;i<256;i++)
       arr[i]=0;
   
   //filling array with pixel frequency
   for(int y=0;y<nr;y++)
   {

       for(int x=0;x<nc;x++)
       {

           arr[img.at<uchar>(y,x)]++;

       }

   }

   int l=*max_element(arr,arr+256);//direct functiion to count max element of an array

   Mat hist(l,256,CV_8UC1,Scalar(255));//making histigram

   for(int x=0;x<256;x++)
   {
       for(int y=l-1;y>=0;y--)
       {

           if(y>(l-arr[x]))
               hist.at<uchar>(y,x)=0;

       }

   }
   
   //making a window
   namedWindow("waste",WINDOW_NORMAL);
   imshow("waste",hist);
   waitKey(0);
   return 0;

} 

 

