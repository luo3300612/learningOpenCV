#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
using namespace std;
int main() {
  cv::VideoCapture cap("1.mp4");
  cv::Mat frame,out;

  cv::namedWindow("Window1");
  cv::namedWindow("Window2");

  double fps = cap.get(cv::CAP_PROP_FPS);
  cv::Size size(
    (int)cap.get(cv::CAP_PROP_FRAME_WIDTH)/2,
    (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)/2
  );

  cv::VideoWriter writer;
  writer.open("3.mp4",cv::VideoWriter::fourcc('M','J','P','G'),fps,size);
  
  for (;;) {
    cap >> frame;
    if (frame.empty())
      break;
    cv::imshow("Window1", frame);
    cv::pyrDown(frame,out);
    cv::imshow("Window2", out);
    writer << out;

    char c = cv::waitKey(10);
    if(c==27) break;
  }
  writer.release();
}