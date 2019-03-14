#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(){
  cv::Mat mat(4,4,0);
  cout << "flags " << mat.flags << endl;
  cout << "flags/ele_num " << mat.flags / 16 << endl;
  cout << "dims " << mat.dims << endl;
  cout << "rows " << mat.rows <<endl;
  cout << "cols " << mat.cols << endl;

  cv::Mat m;
  m.create(3,10,CV_32FC3); // 32-bit floating-point three-channel array
  m.setTo(cv::Scalar(1.0f,0.0f,-1.0f));
  cout << m << endl;


  cv::Mat m2(3,10,CV_32FC3, cv::Scalar(1.0f,0.0f,-1.0f)); // equilent
  return 0;
}