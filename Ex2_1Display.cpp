// 打开图片
// g++ Ex2_1Display.cpp -o main -lopencv_core -lopencv_highgui
// -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab
// -lopencv_imgproc
#include <opencv2/highgui/highgui.hpp>
int main() {
  cv::Mat img = cv::imread("1.jpg");
  if (img.empty())
    return -1;
  cv::namedWindow("Window");
  cv::imshow("Window", img);
  cv::waitKey(0);
  cv::destroyWindow("Window");
  return 0;
}