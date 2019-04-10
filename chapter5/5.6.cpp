#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char const *argv[]) {
  cv::Mat_<uchar> m(3, 3), n(3, 3);
  cv::randu(m, 0, 255);
  cv::randu(n, 0, 255);
  cv::Mat out;
  cv::compare(m, n, out, cv::CMP_GT);
  cv::Mat img = cv::imread("../imgs/1.jpg");
  vector<cv::Mat> splited;
  cv::split(img, splited);
  cv::imshow("Window1", splited[0]);
  cv::imshow("Window2", splited[1]);
  cv::imshow("window3", splited[2]);

  // splited[1] = 0; // check green
  cv::Mat dst;
  cv::merge(splited, dst);
  cv::imshow("Window4", dst);

  cv::Mat clone1, clone2;
  splited[1].copyTo(clone1);
  splited[1].copyTo(clone2);
  double minv = 0.0, maxv = 0.0;
  double *minVal = &minv, *maxVal = &maxv;
  cv::minMaxIdx(splited[1], minVal, maxVal);
  cout << "green channel max value:" << minv << endl;
  cout << "green channel min value:" << maxv << endl;


  clone1 = (maxv-minv)/2.0;

  clone2 = 0;

  cv::compare(splited[1],clone1,clone2,cv::CMP_GE);

  cv::subtract(splited[1],(maxv-minv)/4,splited[1],clone2);

  cv::imshow("Window5",splited[1]);

  cv::waitKey(0);
  return 0;
}
