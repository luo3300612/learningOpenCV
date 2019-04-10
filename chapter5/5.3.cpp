#include<opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
  cv::Mat_<cv::Vec3b> m(100,100);
  m = 0;
  cv::cvtColor(m,m,cv::COLOR_BGR2RGB);
  cv::rectangle(m,{20,5},{40,20},{0,255,0},2);
  cv::imshow("Window",m);
  cv::waitKey(0);
  return 0;
}
