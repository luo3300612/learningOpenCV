#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(){
  cv::Matx<int,3,3> mat(1,2,3,4,5,6,7,8,9);
  cv::Vec<int,3> vec(1,2,3);
  cout << mat << endl;
  cout << vec << endl;
  cout << mat * vec << endl;
  cout << (cv::Matx<int,3,1>)vec << endl; // type-casting
  return 0;
}