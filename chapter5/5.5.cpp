#include<opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
  cv::Mat img = cv::imread("../imgs/1.jpg");
  cv::Mat p1 = img(cv::Range(5,25),cv::Range(10,40));
  cv::Mat p2 = img(cv::Range(50,70),cv::Range(60,90));
  cv::bitwise_not(p1,p1);
  cv::bitwise_not(p2,p2);
  cv::imshow("Window", img);
  cv::waitKey(0);
  return 0;
}
