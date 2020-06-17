#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()

{

   Mat img(100,100,CV_8UC1,Scalar(0));
   for(int z=0;z<100;z++) // along columns
   {

       for(int x=0;x<100;x++)// along rows
       {

           if((((z/10)%2)+(x/10)%2)%2==0)

           img.at<uchar>(z,x)=255;

       }

   }

   namedWindow("waste",WINDOW_NORMAL);
   imshow("waste",img);
   waitKey(0);

   return 0;

}

