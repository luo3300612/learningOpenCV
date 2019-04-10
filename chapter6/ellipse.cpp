#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char const *argv[]) {
  Mat_<Vec3b> m(500, 500);
  m = 0;
  cvtColor(m,m,COLOR_BGR2RGB);
  ellipse(m,{250,250},{100,50},120,0,360,{255,0,0});
  imshow("Window",m);
  waitKey(0);
  return 0;
}
