//morphing images-transition from one image to another



#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <boost/math/common_factor.hpp> 
using namespace std;
using namespace cv;
Mat img1=imread("/home/nil/IP/rubiks.jpg",1);
Mat img2=imread("/home/nil/IP/fruits.png",1);
//Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));

void callback(int th,void *c)
{
 int i,j,r1,c1,r2,c2;
 Mat nimg1;
 Mat nimg2;
 Mat nimg(1000,1000,CV_8UC3,Scalar(0,0,0));
 r1 = img1.rows, c1 = img1.cols,r2=img2.rows,c2=img2.cols;
 //r=boost::math::lcm(r1,r2);
 //c=boost::math::lcm(c1,c2);
 resize(img1,nimg1,Size(1000,1000));
 resize(img2,nimg2,Size(1000,1000));
 
 for(int i=0; i< 1000; i++)
 {
  for(int j=0; j< 1000; j++)
  {
   for(int m=0;m<3;m++){nimg.at<Vec3b>(i,j)[m]=(th*nimg1.at<Vec3b>(i,j)[m]+(100-th)*nimg2.at<Vec3b>(i,j)[m])/100;}
  }
 }
 imshow("moephing",nimg);
}

int main(int argc, char const *argv[])
{
	int t=0;
	//creating a window
	namedWindow("window1",WINDOW_AUTOSIZE);
	//imshow("window1",img);
        createTrackbar("trackbar1","window1",&t,100,callback);
	waitKey(0);	
	return 0;
}

