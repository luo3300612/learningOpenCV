#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

int main() {
  cv::namedWindow("Window1");
  cv::namedWindow("Window2");

  cv::VideoCapture capture("1.mp4");
  double fps = capture.get(cv::CAP_PROP_FPS);
  cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
                (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT));
  cv::VideoWriter writer;
  writer.open("2.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

  cv::Mat logpolar_frame, bgr_frame;

  for (;;) {
    capture >> bgr_frame;
    if (bgr_frame.empty())
      break;

    cv::imshow("Window1", bgr_frame);

    cv::logPolar(bgr_frame, logpolar_frame,
                 cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40,
                 cv::WARP_FILL_OUTLIERS);

    cv::imshow("Window2", logpolar_frame);
    writer << logpolar_frame;

    char c = cv::waitKey(10);
    if (c == 27)
      break;
  }

  capture.release();
}