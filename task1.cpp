#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//Refer to opencv documentation
int main(int argc, char const *argv[])
{
	//Mat image creation
	Mat a(1000,1000,CV_8UC3,Scalar(0,255,0));
	/*//storing green channel pixel intensity
	int x= a.at<Vec3b>(10,10)[1];
	cout << x << endl;
	//output*/
        for(int i=499,i<1000;i++)
        {
         for(int j=0;j<1000;j++)
         a.at<Vec3b>(i,j)={225,0,0};
        }



	//creating a window
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",a);
	waitKey(0);	
	return 0;
}
