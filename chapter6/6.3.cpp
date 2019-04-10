#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[]) {
  cv::VideoCapture cap;
  cv::Mat frame;
  cap.open("../chapter2/1.mp4");
  double t, fps;
  while (true) {
    t = (double)cv::getTickCount();
    cap >> frame;
    if (frame.empty()) {
      break;
    }
    if (cv::waitKey(12) >= 0) {
      break;
    }
    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    fps = 1 / t;
    char s[10];

    sprintf(s, "%.2f", fps);
    std::string f = s;
    f = "fps:" + f;

    cv::putText(frame,f,{20,40},cv::FONT_HERSHEY_SIMPLEX,1,{255,0,0});

    cv::imshow("Window", frame);
  }
  return 0;
}
