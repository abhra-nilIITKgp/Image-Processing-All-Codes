#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"

using namespace cv;

using namespace std;

int main()

{

   Mat img=imread("fruits.png",1);

   int nc= img.cols;

   int nr=img.rows;

   int rmax=50;

   int bmax=50;

   int gmax=50;

   int rmin=50;

   int bmin=50;

   int gmin=50;

   namedWindow("waste",WINDOW_NORMAL);

   Mat img1(img.rows,img.cols,CV_8UC3,Scalar(255,255,255));

   createTrackbar("Red Max","waste",&rmax,254);

   createTrackbar("Blue Max","waste",&gmax,254);

   createTrackbar("Green Max","waste",&bmax,254);

   createTrackbar("Red Min","waste",&rmin,254);

   createTrackbar("Blue Min","waste",&gmin,254);

   createTrackbar("Green Min","waste",&bmin,254);

   while(45)

   {

       for(int j=0;j<nr;j++)

       {

           for(int i=0;i<nc;i++)

           {

               if((img.at<Vec3b>(j,i)[2]>rmax||img.at<Vec3b>(j,i)[2]<rmin)||(img.at<Vec3b>(j,i)[0]>bmax||img.at<Vec3b>(j,i)[0]<bmin)||(img.at<Vec3b>(j,i)[1]>gmax||img.at<Vec3b>(j,i)[1]<gmin))

               {

                   img1.at<Vec3b>(j,i)[0]=0;

                   img1.at<Vec3b>(j,i)[1]=0;

                   img1.at<Vec3b>(j,i)[2]=0;

               }                   

               else

               {

                   img1.at<Vec3b>(j,i)=img.at<Vec3b>(j,i);

               }

           }

       }

       imshow("waste",img1);

       waitKey(1);

   }

   waitKey(0);

   return 0;

} 

