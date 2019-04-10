#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char const *argv[]) {
  cv::Mat_<cv::Vec3b> m(300, 300);
  cv::Point2i start = {150, 150};
  double angle;
  int length = 100;
  int endx, endy;
  while (true) {
    cv::Mat m4, m8;
    m.copyTo(m4);
    m.copyTo(m8);
    cout << "input a rad" << endl;
    cin >> angle;
    if (angle < 0) {
      break;
    }
    endx = int(start.x + cos(angle) * length);
    endy = int(start.y + sin(angle) * length);

    cv::Point2i end = {endx, endy};
    cout << "linetype=4, " << cv::LineIterator(m4, start, end, 4).count
         << "points" << endl;
    cout << "linetype=8, " << cv::LineIterator(m8, start, end, 8).count
         << "points" << endl;
    cv::line(m4, start, end, {255, 0, 0}, 1, 4);
    cv::line(m8, start, end, {0, 255, 0}, 1, 8);
    cv::imshow("Window1", m4);
    cv::imshow("Window2", m8);
    cv::waitKey(0);
  }
  return 0;
}
