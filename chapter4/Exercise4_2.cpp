#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  int H = 5;
  int W = 10;
  Mat_<uchar> m(H, W);
  Mat_<float> inte(H, W);
  randu(m, 0, 255);
  cout << m << endl;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(i==0&&j==0){
        inte(i, j) = m(i, j);
      }
      else if(i==0){
        inte(i,j) = m(i,j) + inte(i,j-1);
      }
      else if(j==0){
        inte(i,j) = inte(i-1,j) + m(i,j);
      }
      else{
        inte(i,j) = inte(i,j-1) + inte(i-1,j) - inte(i-1,j-1)+m(i,j);
      }
    }
  }
  cout << inte << endl;

  int stx,sty,edx,edy;
  cout << "输入一个矩形区域的左上点和右下点位置" << endl;
  cin >> stx >> sty >> edx >> edy;
  cout << inte(edx,edy)-inte(edx,sty-1) -inte(stx-1,edy) + inte(stx-1,sty-1) << endl;
}

// e，调整integral image的每个位置的值为该位置到矩形从原点出发的45度角的直线围成的梯形的面积