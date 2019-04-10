#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
  Mat m(100,100,CV_8UC3);
  m = 0;
  Point point(50,50);
  circle(m,point,4,100);
  imshow("Window",m);
  waitKey(0);
  return 0;
}
