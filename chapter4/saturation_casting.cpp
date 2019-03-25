#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
  uchar Vxy = 10;
  Vxy = cv::saturate_cast<uchar>((Vxy - 128) * 2 + 128);
  cout << int(Vxy) << endl;
  Vxy = 10;
  Vxy = (Vxy - 128) * 2 + 128;
  cout << int(Vxy) << endl;
  return 0;
}

//	g++ -o main saturation_casting.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
