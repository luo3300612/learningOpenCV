#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main(){
  cv::RNG rng = cv::theRNG();
  // cout << "an interger "<< (int)rng << endl;
  // cout << "another integer" << int(rng) << endl;
  // cout << "A float " << (float)rng << endl;
  // cout << "another float" << float(rng) << endl;
  cout << "uniform:" << endl;
  cout << "1. " << float(rng) << endl;
  cout << "2. " << float(rng) << endl;
  cout << "3. " << float(rng) << endl;

  cout << "gaussian:" << endl;
  cout << "1. " << rng.gaussian(1.0) << endl;
  cout << "2. " << rng.gaussian(2.0) << endl;
  cout << "3. " << rng.gaussian(3.0) << endl;

  cout << "uchar:" << endl;
  cout << "1. " << int(uchar(rng)) << endl;
  cout << "2. " << int(uchar(rng)) << endl;
  cout << "3. " << int(uchar(rng)) << endl;

}