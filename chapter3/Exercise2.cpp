#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(){
  cv::Matx33f mat(1,2,3,4,5,6,7,8,9);
  cv::Vec3f vec(1,1,1);
  cout << mat <<endl;
  cout << vec <<endl;
  cout << mat * vec << endl;
  return 0;
}