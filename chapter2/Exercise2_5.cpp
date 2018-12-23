#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
int g_factor = 0;

void onTrackbarSlide(int pos, void *) { 
  cout<<"pos = " << pos << endl;
  g_factor = pos; }

int main() {
  cv::VideoCapture cap("1.mp4");

  cv::Size size;

  cv::namedWindow("Window1");
  cv::namedWindow("Window2");

  cv::createTrackbar("T", "Window2", 0, 3, onTrackbarSlide);
  cv::Mat frame, out;

  int width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  int fps = cap.get(cv::CAP_PROP_FPS);

  for (;;) {
    cap >> frame;

    imshow("Window1", frame);
    out = frame;
    for(int i = 0; i <= g_factor; i++){
      cv::pyrDown(out, out);
    }
    

    imshow("Window2", out);

    char c = cv::waitKey(1000/fps);
    if (c == 27) {
      break;
    }
  }
}