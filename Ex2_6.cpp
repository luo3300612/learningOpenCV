#include<opencv2/opencv.hpp>

int main(){
  cv::Mat img1,img2;

  cv::namedWindow("Window1",cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Window2",cv::WINDOW_AUTOSIZE);

  img1 = cv::imread("1.jpg");
  cv::imshow("Window1",img1);

  cv::pyrDown(img1, img2);
  cv::imshow("Window2",img2);

  cv::waitKey(0);

  return 0;
}