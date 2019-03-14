#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  cv::namedWindow("Window1");
  cv::VideoCapture cap;
  if (argc == 1) {
    cap.open(0);
  } else {
    cap.open(argv[1]);
  }
  if (!cap.isOpened()) {
    std::cerr << "Couldn't open capture." << std::endl;
    return -1;
  }
  cv::Mat frame;
  for (;;) {
    cap >> frame;
    if (frame.empty())
      break;
    cv::imshow("Window1", frame);
    if (cv::waitKey(33) > 0) {
      break;
    }
  }
  return 0;
}
/*
g++ -o main learningopencv/chapter2/Ex2_10camera.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
*/