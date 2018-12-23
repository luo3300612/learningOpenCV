#include<opencv2/opencv.hpp>

int main(){
  cv::Mat out,img = cv::imread("1.jpg");
  cv::namedWindow("Window1");
  cv::cvtColor(img,out,cv::COLOR_BGR2GRAY);
  cv::imshow("Window1",out);
  cv::waitKey(0);
  cv::destroyWindow("Window1");
  return 0;
}