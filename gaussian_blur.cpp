#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"

#include<iostream>

#include<cmath>

using namespace cv;

using namespace std;

int main()

{

   Mat img=imread("/home/nil/IP/index.jpg",1);

   int nc= img.cols;

   int nr=img.rows;

   Mat img_pad(nr+2,nc+2,CV_8UC3,Scalar(0,0,0));

   for(int y=0;y<nr;y++)

   {

       for(int x=0;x<nc;x++)

       {

           img_pad.at<Vec3b>(y+1,x+1)[0]=img.at<Vec3b>(y,x)[0];

           img_pad.at<Vec3b>(y+1,x+1)[1]=img.at<Vec3b>(y,x)[1];

           img_pad.at<Vec3b>(y+1,x+1)[2]=img.at<Vec3b>(y,x)[2];

       }

   }

   Mat img_fin(nr,nc,CV_8UC3,Scalar(255,255,255));

   for(int y=1;y<nr+1;y++)

   {

       for(int x=1;x<nc+1;x++)

       {

           for(int z=0;z<3;z++)

           img_fin.at<Vec3b>(y,x)[z]=(4*img_pad.at<Vec3b>(y,x)[z]+2*img_pad.at<Vec3b>(y+1,x)[z]+2*img_pad.at<Vec3b>(y,x+1)[z]+img_pad.at<Vec3b>(y+1,x+1)[z]+2*img_pad.at<Vec3b>(y-1,x)[z]+2*img_pad.at<Vec3b>(y,x-1)[z]+img_pad.at<Vec3b>(y-1,x-1)[z]+img_pad.at<Vec3b>(y-1,x+1)[z]+img_pad.at<Vec3b>(y+1,x-1)[z])/16;

       }

   }

   namedWindow("waste",WINDOW_NORMAL);

   imshow("waste",img_fin);

   waitKey(0);

   return 0;

} 

 

