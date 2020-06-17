#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"

using namespace cv;

using namespace std;

int main()

{

   Mat img=imread("fruits.jpg",0);

   int nc= img.cols;

   int nr=img.rows;

   for(int j=0;j<nr;j++)

   {

       for(int i=0;i<nc/2;i++)

       {

           int temp;

           temp=img.at<uchar>(j,i);

           img.at<uchar>(j,i)=img.at<uchar>(j,nc-1-i);

           img.at<uchar>(j,nc-1-i)=temp;

       }

   }

   namedWindow("waste",WINDOW_NORMAL);

   imshow("waste",img);

   waitKey(0);

   return 0;

}

