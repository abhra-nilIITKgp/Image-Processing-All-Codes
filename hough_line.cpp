#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>

using namespace cv;
using namespace std;

int main()
{

   Mat img=imread("/home/nil/IP/samps/A1.png",0);

   int nc= img.cols;

   int nr=img.rows;

   double l=sqrt(pow(nc,2)+pow(nr,2));

   Mat hist(l,360,CV_8UC1,Scalar(0));

   for(int y=0;y<nr;y++)

   {

       for(int x=0;x<nc;x++)

       {

           if(img.at<uchar>(y,x)==255)

           {

               for(int deg=0;deg<360;deg++)

               {

                   double rad=(double)(deg)*M_PI/180;

                   double r=x*cos(rad)+y*sin(rad);

                   if(r>0)

                   if(hist.at<uchar>(l-r-1,deg)<252)

                   hist.at<uchar>(l-r-1,deg)++;

               }

           }      

       }

   }

   int count=0;

   vector<pair<int,int>> points;

   namedWindow("waste",WINDOW_NORMAL);           

   for(int y=0;y<l;y++)

   {

       for(int x=0;x<360;x++)

       {

           if(hist.at<uchar>(y,x)>80)

           {

               cout<<x<<"\t"<<y<<endl;

               points.push_back(make_pair(x,l-1-y));

               count++;

           }

       }

   }

   cout<<count<<endl;

   int s=points.size();

   Mat fin(nr,nc,CV_8UC1,Scalar(0));

   for(int z=0;z<s;z++)

   {

       double y2,x1,y1,x2;

       double r=points[z].second;

       double theta=points[z].first;

       double rad=(theta)*M_PI/180;

       if(theta<90&&theta>0)

       {

           y2=0;x1=0;

       }

       else if(theta>90&&theta<180)

       {

           y2=l-1;

           x1=0;

       }

       else if(theta>270&&theta<360)

       {

           y2=l-1;

           x1=0;

       }

       else if(theta==0)

       {

           y2=l-1;

           x1=r-1;

       }

       x2=(r-y2*sin(rad))/cos(rad);

       y1=(r-x1*cos(rad))/sin(rad);

       Point2d a(x1,y1),b(x2,y2);

       line(fin,a,b,Scalar(255),1,CV_AA);

   }

   imshow("waste",fin);   

   waitKey(0);

   return 0;

} 

 
