#include <opencv4/opencv2/opencv.hpp>

int main() {
  cv::VideoCapture cap("1.mp4");
  cv::VideoWriter writer;
  cv::Size size(cap.get(cv::CAP_PROP_FRAME_WIDTH),
                cap.get(cv::CAP_PROP_FRAME_HEIGHT));
  writer.open("out.mp4", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
              cap.get(cv::CAP_PROP_FPS), size);
  cv::Mat frame;

  for(;;){
    cap >> frame;
    if(frame.empty())break;
    writer << frame;
  }
  writer.release();
}