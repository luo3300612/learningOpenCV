#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

using namespace std;

cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos); //????
}

int main() {
  cv::namedWindow("Window1", cv::WINDOW_AUTOSIZE);
  g_cap.open("1.mp4");
  int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
  cv::createTrackbar("Position", "Window1", 0, frames, onTrackbarSlide);
  cv::Mat frame;
  for (;;) {
    g_cap >> frame;
    if (frame.empty())
      break;
    int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
    cv::setTrackbarPos("Position", "Window1",
                       current_pos); // 保证进度条的位置和播放进度一致
    cv::imshow("Window1", frame);
    if (cv::waitKey(33) > 0) {
      break;
    }
  }
  return (0);
}