#include <opencv2/opencv.hpp>

void example2_5(const cv::Mat &image) {
  cv::namedWindow("in", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("out", cv::WINDOW_AUTOSIZE);

  cv::imshow("in", image);

  cv::Mat out;

  cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
  cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

  cv::imshow("out", out);

  cv::waitKey(0);
}

int main(){
  cv::Mat img = cv::imread("1.jpg");
  example2_5(img);
}