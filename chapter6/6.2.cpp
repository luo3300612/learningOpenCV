#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[]) {
  cv::Mat img = cv::imread("../imgs/1.jpg");
  cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
  cv::putText(img, "hello bitch", {100, 100}, cv::FONT_HERSHEY_SCRIPT_COMPLEX,
              1.2, {255, 0, 0});
  cv::imshow("Window",img);
  cv::waitKey(0);
  return 0;
}
