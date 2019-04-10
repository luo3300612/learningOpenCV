#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[]) {
  cv::Mat_<uchar> m(210, 210);
  m = 0;
  for (int i = 1; i * 10 < 210 - i * 10; i++) {
    m(cv::Rect(10 * i, 10 * i,210-10*i*2,210-10*i*2)) = 20 * i;
  }
  cv::imshow("Window", m);
  cv::waitKey(0);
  return 0;
}
