#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
  cv::Mat_<uchar> img(500, 500);
  cv::namedWindow("Window1");
  int num;
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 50; j++) {
      cv::imshow("Window1", img);
      char c = (char)cv::waitKey(10);
      if (c == 'q')
        break;

      cout << "please typein a number between 0~255" << endl;
      cin >> num;
      if (num <= 0 || num > 255) {
        cout << "invalid" << endl;
        continue;
      }

      img(cv::Rect(i * 10, j*20, 10, 20)) = num;
    }
  }

  return 0;
}