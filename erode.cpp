#include<iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
int main(){
    Mat out;
    Mat in;
    Mat el;
    in = imread("im.jpg",IMREAD_COLOR);
    bitwise_not(in,in);
    imshow("in",in);
    int erosion_size = 0;
    int erosion_elem = 0;
    int erosion_type = 0;
    if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
    else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
    else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

    cv::erode(in,out,el);
    if(out.empty()){
        return -1;
    }
    imshow("output",out);

    waitKey(0);
    return 0;
}


