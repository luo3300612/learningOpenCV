#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
  cv::RNG rng = cv::theRNG();
  cv::Mat_<cv::Vec3b> mat(100,1);
  cv::Vec3d mean = {64,192,128};
  cv::Vec3d std = {10,10,2};
  rng.fill(mat,cv::RNG::NORMAL,mean,std);
  cout << mat << endl;
}
