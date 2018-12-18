#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat img = cv::imread("1.jpg");
  int x = 16;
  int y = 32;

  cv::Vec3b intensity = img.at<cv::Vec3b>(y, x);

  uchar blue = intensity[0];
  uchar green = intensity[1];
  uchar red = intensity[2];

  std::cout << "At (x, y) = (" << x << ", " << y << ")： (blue, green, red) = ("
            << (unsigned int)blue << ", " << (unsigned int)green << ", "
            << (unsigned int)red << ")" << std::endl;
}

// 什么是uchar
// 什么是cv::Vec3b
// 不转成unsigned int 是什么
// at那是什么奇怪的语法