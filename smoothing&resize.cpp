#include<iostream>
#include <opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat in;
    Mat out;

     in =imread("pok.jpg",IMREAD_COLOR);
     resize(in ,in ,  Size(500,500));
     GaussianBlur(in, out, Size(5,5),0);
     imshow("input" , in);
     imshow("output", out);
     waitKey(0);
     return 0;

}