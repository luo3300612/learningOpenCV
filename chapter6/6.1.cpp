#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[]) {
  cv::Mat m = cv::imread("../imgs/1.jpg");
  cv::circle(m, {100, 100}, 20, {0, 0, 255});
  cv::ellipse(m, {100, 100}, {40, 20}, 0, 0, 360, {255, 0, 0});
  std::vector<cv::Point2i> pts = {
      {20, 20}, {20, 30}, {30, 60}, {30, 40}, {40, 50}};
  std::vector<cv::Point2i> pts2 = {
      {120, 120}, {120, 130}, {130, 160}, {130, 140}, {140, 150}};
  cv::fillConvexPoly(m, pts, {0, 255, 0});
  cv::line(m, {0, 0}, {10, 100}, {255, 0, 0});
  cv::rectangle(m, {200, 200}, {230, 230}, {0, 0, 255});
  cv::polylines(m, pts2, true, {0, 255, 0});
  cv::putText(m, "Hello bitch", {170, 170}, cv::FONT_HERSHEY_SCRIPT_COMPLEX, 2,
              {0, 255, 0});
  cv::imshow("Window",m);
  cv::waitKey(0);
  return 0;
}
