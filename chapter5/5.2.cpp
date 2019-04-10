#include<opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
  cv::Mat_<cv::Vec3b> m(100,100);
  m = 0;
  m(50,50) = {100,100,100};
  cv::rectangle(m,{20,5},{40,20},100,3);
  cv::imshow("Window",m);
  cv::waitKey(0);  
  return 0;
}
