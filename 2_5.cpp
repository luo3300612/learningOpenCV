#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
int g_factor = 1.5;

void onTrackbarSlide(int pos, void *) { 
  cout<<"pos = " << pos << endl;
  g_factor = pos + 2; }

int main() {
  cv::VideoCapture cap("1.mp4");

  cv::Size size;

  cv::namedWindow("Window1");
  cv::namedWindow("Window2");

  cv::createTrackbar("T", "Window2", 0, 6, onTrackbarSlide);
  cv::Mat frame, out;

  int width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

  for (;;) {
    cap >> frame;

    imshow("Window1", frame);

    size.height = (int)(height / g_factor);
    size.width = (int)(width / g_factor);

    cv::pyrDown(frame, out, size);

    imshow("Window2", out);

    char c = cv::waitKey(100);
    if (c == 27) {
      break;
    }
  }
}