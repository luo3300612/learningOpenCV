#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
  cv:: Mat_<float> mat(20,1);
  cv::RNG rng = cv::RNG();

  rng.fill(mat,cv::RNG::UNIFORM,0.,1.); // cv::RNG::NORMAL
  cout << mat << endl;

  rng.fill(mat,cv::RNG::NORMAL,0.,1.);
  cout << mat << endl;

  cv::Mat_<uchar> mat2(20,1);
  rng.fill(mat2,cv::RNG::UNIFORM,0,255);
  cout << mat2 << endl;

  cv::Mat_<cv::Vec3b> mat3(20,1);
  rng.fill(mat3,cv::RNG::UNIFORM,0,255);
  cv::imshow("Window1",mat3);
  cv::waitKey(0);

  return 0;
}
