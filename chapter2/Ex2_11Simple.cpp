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
	g++ -o main Ex2_11Simple.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
