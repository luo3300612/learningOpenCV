#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(){
  // create a mat
  // m(int rows,int cols,int type,const Scalar& init_value)
  cv::Mat m(5,5,CV_16F,1); 

  // waitkey
  char c = (char)cv::waitKey(10);
  if (c == 's'){}

  return 0;
}