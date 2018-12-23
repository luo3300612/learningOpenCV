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

  std::cout << "----------Before----------" << std::endl;
  std::cout << "At (x, y) = (" << x << ", " << y << ")： (blue, green, red) = ("
            << (unsigned int)blue << ", " << (unsigned int)green << ", "
            << (unsigned int)red << ")" << std::endl;

  img.at<cv::Vec3b>(y, x) = {0, 0, 0};

  cv::Vec3b intensity2 = img.at<cv::Vec3b>(y, x);

  uchar blue2 = intensity2[0];
  uchar green2 = intensity2[1];
  uchar red2 = intensity2[2];

  std::cout << "----------After----------" << std::endl;
  std::cout << "At (x, y) = (" << x << ", " << y << ")： (blue, green, red) = ("
            << (unsigned int)blue2 << ", " << (unsigned int)green2 << ", "
            << (unsigned int)red2 << ")" << std::endl;
}

// 什么是uchar unsigned char
// 什么是cv::Vec3b vector unchar
// 不转成unsigned int 是什么
// at那是什么奇怪的语法