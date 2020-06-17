//edge detection by sobel filter or prewitt filter 
//here done by sobel, for prewitt only change multiplication factors

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include<cmath>

using namespace cv;
using namespace std;

int main()

{

   Mat img=imread("/home/nil/IP/rubiks.jpg",0);//reading image
   int nc= img.cols;
   int nr=img.rows;
   int th1=0;
   int th2=3*th1;
   Mat img_fin(nr,nc,CV_8UC1,Scalar(0));//new image 
   namedWindow("waste",WINDOW_AUTOSIZE);//creting window
   createTrackbar("Threshold","waste",&th1,800);//creating taskbar

//infinite loop doing same task as callback function
   while(1)
   {

     /*  for(int y=1;y<nr-1;y++)
       {

           for(int x=1;x<nc-1;x++)
           {
               //multiplying pixels by multiplying factors

               double sobelx=0,sobely=0,sobel=0;
               int sx1=-1*img.at<uchar>(y-1,x-1);
               int sx2=img.at<uchar>(y-1,x+1);
               int sx3=-2*img.at<uchar>(y,x-1);
               int sx4=2*img.at<uchar>(y-1,x-1);
               int sx5=-1*img.at<uchar>(y+1,x-1);
               int sx6=img.at<uchar>(y+1,x+1);

               sobelx=(sx1+sx2+sx3+sx4+sx5+sx6)/4;

               int sy1=1*img.at<uchar>(y-1,x-1);
               int sy2=img.at<uchar>(y-1,x+1);
               int sy3=-2*img.at<uchar>(y+1,x);
               int sy4=2*img.at<uchar>(y-1,x);
               int sy5=-1*img.at<uchar>(y+1,x-1);
               int sy6=-1*img.at<uchar>(y+1,x+1);

               sobely=(sy1+sy2+sy3+sy4+sy5+sy6)/4;          

               sobel=sqrt(pow(sobelx,2)+pow(sobely,2));

               if(sobel>th)
                   img_fin.at<uchar>(y,x)=255;
               else
                   img_fin.at<uchar>(y,x)=0;

           }

       }*/
       Canny(img,img_fin,th1,th2,3);
       imshow("waste",img_fin);//displaying image

       waitKey(1);

   }

   waitKey(0);

   return 0;

} 

 
