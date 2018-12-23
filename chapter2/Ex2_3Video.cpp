// 打开视频
// 没有声音
// 编译
// g++ Ex2_3Video.cpp -o main -lopencv_core -lopencv_highgui -lopencv_imgcodecs
// -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
  cv::namedWindow("Window1", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cap;
  cap.open("1.mp4");
  cv::Mat frame;
  for (;;) {
    cap >> frame;
    if (frame.empty())
      break;
    cv::imshow("Window1", frame);
    if (cv::waitKey(33) >= 0) // 这个数字控制了视频的播放速度
      break;
  }
}