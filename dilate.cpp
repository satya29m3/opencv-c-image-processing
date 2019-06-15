#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
int main(){
    Mat out;
    Mat in;
    Mat el;
    in = imread("im.jpg",IMREAD_COLOR);
    bitwise_not(in,in);
    imshow("in",in);
    int dilation_size = 0;
    int dilation_elem = 0;
    
    int dilation_type = 0;
    if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
    else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
    else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
    
    dilate( in, out, el );
  
    if(out.empty()){
        return -1;
    }
    imshow("output",out);

    waitKey(0);
    return 0;
}