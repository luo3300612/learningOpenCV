// 打开图片
#include <opencv2/highgui/highgui.hpp>
int main() {
  cv::Mat img = cv::imread("1.jpg");
  if (img.empty())
    return -1;
  cv::namedWindow("Window1");
  cv::imshow("Window1", img);
  cv::waitKey(0);
  cv::destroyWindow("Window1");
  return 0;
}