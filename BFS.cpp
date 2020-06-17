#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include<algorithm>
#include<cmath>
#include<list>

using namespace cv;
using namespace std;

list<pair<int,int>> listgen( pair<int,int> s, Mat pad)

{

   list<pair<int,int>> adj;

   for(int z=-1;z<2;z++)

   {

       for(int c=-1;c<2;c++)

       {

           if(pad.at<uchar>(s.second+z,s.first+c)==255)

           {

               adj.push_back(make_pair(s.first+c,s.second+z));

           }

       }

   }

   return adj;

}

int main()

{

   Mat img=imread("/home/nil/IP/samps/Temp.jpg",0);

   int nc= img.cols;

   int nr=img.rows;

   Mat pad(nr+2,nc+2,CV_8UC1,Scalar(0));

   for(int y=0;y<nr;y++) //binarize

   {

       for(int x=0;x<nc;x++)

       {

           if(img.at<uchar>(y,x)>100)

               pad.at<uchar>(y+1,x+1)=255;

       }

   }

   Mat visited(nr,nc,CV_8UC1,Scalar(0));

   int count = 0;

   for(int y=1;y<nr+2;y++) // bfs

   {

       for(int x=1;x<nc+2;x++)

       {

           if(pad.at<uchar>(y,x)==255&&visited.at<uchar>(y-1,x-1)==0) //candidate for bfs

           {

               //cout<<endl;

               count++;

               list<pair<int,int>> q;

               visited.at<uchar>(y-1,x-1)=255;

               q.push_back(make_pair(x,y));

               pair<int,int> s;

               list<pair<int,int>>::iterator i;

               while(!q.empty())

               {

                   s=q.front();

                   //cout<<s.first<<"\t"<<s.second<<endl;

                   list<pair<int,int>> adj= listgen(s,pad);

                   q.pop_front();

                   for(i=adj.begin();i!=adj.end();++i)

                   {

                       int xl=(*i).first;

                       int yl=(*i).second;

                       if(visited.at<uchar>(yl-1,xl-1)==0)

                       {

                           visited.at<uchar>(yl-1,xl-1)=255;

                           q.push_back(*i);

                       }

                   }

               }

           }

       }

   }

   cout<<count<<endl;

   namedWindow("waste",WINDOW_NORMAL);

   imshow("waste",visited);

   waitKey(0);

   return 0;

} 

 
