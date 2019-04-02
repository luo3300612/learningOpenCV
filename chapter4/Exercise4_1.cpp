#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

using namespace std;
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux

char getch() {
  /*#include <unistd.h>   //_getch*/
  /*#include <termios.h>  //_getch*/
  char buf = 0;
  struct termios old = {0};
  fflush(stdout);
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  printf("%c\n", buf);
  return buf;
}

int main() {
  cv::Mat_<uchar> img(500, 500);
  cv::Mat_<cv::Vec3b> imgRGB(500,500);
  cv::namedWindow("Window1");
  int num;
  int flag = 0;
  char c;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 25; j++) {
      if(flag==0){
        cv::imshow("Window1", img);
      }
      else{
        cout << "show rgb" << endl;
        cv::imshow("Window1", imgRGB);
      }
      
      char c = (char)cv::waitKey(10);
      if (c == 'q')
        break;

      cout << "please typein a number between 0~255" << endl;
      c = getch();
      if (int(c) == 10) {
        img(cv::Rect(i * 10, j * 20, 10, 20)) = 0;
        continue;
      } else if (int(c) == 127) {
        if (j > 1) {
          j=j-2;
          img(cv::Rect(i * 10, (j+1) * 20, 10, 20)) = 0;
        } 
        else if(j==1){
          i--;
          j = 24;
          img(cv::Rect((i+1) * 10, 0, 10, 20)) = 0;
        }
        else{
          i--;
          j = 23;
          img(cv::Rect(i * 10, (j+1) * 20, 10, 20)) = 0;
        }
        continue;
      } else if(int(c)==52){ // left
        if(i==0){
          j--;
        }
        else{
          i--;
          j--;
        }
        continue;
      } else if(int(c)==54){ //right
        if(i==49){
          j--;
        }
        else{
          i++;
          j--;
        }
        continue;
      } else if(int(c)==50){ // down
        if(j==24){
          j--;
        }
        else{
          continue;
        }
      } else if(int(c)==56){ // up
        if(j==0){
          j--;
        }
        else{
          j = j - 2;
        }
        continue;
      } else if(int(c)==32){
        int nrows = img.rows;
        int ncols = img.cols;
        // cvtColor(img, imgRGB, cv::COLOR_GRAY2RGB);
        for(int k=0;k<nrows;k++){
          for(int l=0;l<ncols;l++){
            imgRGB(k,l)[img(k,l)%3] = img(k,l);
          }
        }
        
        flag = 1;
        continue;
      }

      img(cv::Rect(i * 10, j * 20, 10, 20)) = int(c);
      cout << "now " << int(c) << endl;
    }
  }

  return 0;
}