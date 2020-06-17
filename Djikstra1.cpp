#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"

#include<iostream>

#include<algorithm>

#include<cmath>

#include<fstream>

#include<list>

using namespace cv;

using namespace std;

list<pair<float,pair<int,int>>> listgen( pair<int,int> s, Mat pad)

{

   s.first++;

   s.second++;

   list<pair<float,pair<int,int>>> adj;

   if(pad.at<uchar>(s.second+1,s.first+1)==255)

       adj.push_back(make_pair(sqrt(2),make_pair(s.first+1,s.second+1)));

   if(pad.at<uchar>(s.second+1,s.first-1)==255)

       adj.push_back(make_pair(sqrt(2),make_pair(s.first+1,s.second-1)));

   if(pad.at<uchar>(s.second-1,s.first+1)==255)

       adj.push_back(make_pair(sqrt(2),make_pair(s.first-1,s.second+1)));

   if(pad.at<uchar>(s.second-1,s.first-1)==255)

       adj.push_back(make_pair(sqrt(2),make_pair(s.first-1,s.second-1)));

   if(pad.at<uchar>(s.second,s.first+1)==255)

       adj.push_back(make_pair(1,make_pair(s.first,s.second+1)));

   if(pad.at<uchar>(s.second+1,s.first)==255)

       adj.push_back(make_pair(1,make_pair(s.first+1,s.second)));

   if(pad.at<uchar>(s.second-1,s.first)==255)

       adj.push_back(make_pair(1,make_pair(s.first-1,s.second)));

   if(pad.at<uchar>(s.second,s.first-1)==255)

       adj.push_back(make_pair(1,make_pair(s.first,s.second-1)));

   return adj;

}

int main()

{

   fstream log1;

   log1.open("log.txt");

   Mat img1=imread("/home/nil/IP/samps/Temp.jpg",1);

   Mat pathf=img1.clone();

   Mat img;

   cvtColor(img1,img,CV_BGR2GRAY);

   int nc= img.cols;

   int nr=img.rows;

   Mat pad(nr+2,nc+2,CV_8UC1,Scalar(0));

   for(int y=0;y<nr;y++) //binarize

   {

       for(int x=0;x<nc;x++)

       {

           if(img.at<uchar>(y,x)>100)

               pad.at<uchar>(y+1,x+1)=255;

           else

           {

               pad.at<uchar>(y+1,x+1)=0;

           }

          

       }

   }

   namedWindow("waste",WINDOW_NORMAL);

   Mat visited(nr,nc,CV_8UC1,Scalar(255));

   int count = 0;

   int n=nc*nr;

   float d[nr][nc];

   pair<int,int> p[nr][nc];

   for(int y=0;y<nr;y++)

   {

       for(int x=0;x<nc;x++)

       {

           d[x][y]=INT16_MAX;

           p[x][y].first=-1;

           p[x][y].second=-1;

       }

   }

   d[0][0]=0;

   p[0][0].first=0;

   p[0][0].second=0;

   list<pair<float,pair<int,int>>>::iterator i;

   list<pair<float,pair<int,int>>> adj;

   //log1<<nc<<"\t"<<nr<<endl;

   for(int y=0;y<nr;y++)//dijkstra

   {

       for(int x=0;x<nc;x++)

       {

           if(pad.at<uchar>(y+1,x+1)==255)

           {

               pair<int,int> v=make_pair(-1,-1);

               for(int z=0;z<nr;z++)

               {

                   for(int c=0;c<nc;c++)

                   {

                       if(visited.at<uchar>(z,c)==255)

                       {

                           if(v.first==-1&&v.second==-1)

                           {  

                               v.first=c;

                               v.second=z;

                           }

                           else if(d[c][z]<d[v.first][v.second])

                           {

                               v.first=c;

                               v.second=z;                       

                           }

                       }

                   }

               }

               //log1<<x<<"\t"<<y<<"\t"<<v.first<<"\t"<<v.second<<"\t"<<d[v.first][v.second]<<"\t"<<p[v.first][v.second].first<<"\t"<<p[v.first][v.second].second<<endl;

               if(d[v.first][v.second]==INT16_MAX)

               {

                   break;

               }  

               visited.at<uchar>(v.second,v.first)=0;

               //imshow("waste",visited);

               //waitKey(1);

               adj= listgen(v,pad);

               for(i=adj.begin();i!=adj.end();++i)

               {

                   float len=(*i).first;

                   pair<int,int> to;

                   if((*i).second.first==0||(*i).second.second==0)

                   continue;

                   to.first= (*i).second.first-1;

                   to.second= (*i).second.second-1;

                   if(d[v.first][v.second]+len<d[to.first][to.second])

                   {

                       d[to.first][to.second]=d[v.first][v.second]+len;

                       p[to.first][to.second].first=v.first;

                       p[to.first][to.second].second=v.second;

                   }

               }

           }

       }

   }

   cout<<"a"<<d[289][289]<<endl;

   //the coordinates stored are for img and not pad!!!!!

   list<pair<int,int>> path;

   pair<int,int> v =make_pair(289,289);

   while(v!=make_pair(0,0))

   {

       path.push_back(v);

       v.first=p[v.first][v.second].first;

       v.second=p[v.first][v.second].second;

      

   }

   //colour the path

   list<pair<int,int>>::iterator i2;

   i2=path.begin();

   for(i2;i2!=path.end();++i2)

   {

       int xl=(*i2).first;

       int yl=(*i2).second;

       pathf.at<Vec3b>(yl,xl)[0]=0;

       pathf.at<Vec3b>(yl,xl)[1]=0;

       pathf.at<Vec3b>(yl,xl)[2]=255;

   }

   imshow("waste",visited);

   waitKey(0);

   imshow("waste",pathf);

   waitKey(0);

   return 0;

} 

 
