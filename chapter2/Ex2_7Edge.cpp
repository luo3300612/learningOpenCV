#include <opencv2/opencv.hpp>

int main() {

  cv::Mat img_rgb, img_gry, img_cny;

  cv::namedWindow("Window1");
  cv::namedWindow("Window2");

  img_rgb = cv::imread("1.jpg");

  cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
  cv::pyrDown(img_gry, img_gry);
  cv::pyrDown(img_gry,img_gry);
  cv::imshow("Window1", img_gry);

  cv::Canny(img_gry, img_cny, 10, 100, 3, true);
  cv::imshow("window2", img_cny);

  cv::waitKey(0);
}