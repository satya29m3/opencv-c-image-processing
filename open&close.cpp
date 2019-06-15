#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;

int morph_elem = 0;
int morph_size = 5;
int morph_operator = 0;

int main(){
    Mat in;
    Mat open,close;
    Mat el = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    in = imread("im.jpg",IMREAD_COLOR);
    morphologyEx(in,open,MORPH_OPEN,el);
    imshow("OPEN",open);

    Mat ele = getStructuringElement( morph_elem, Size( 2*3 + 1, 2*3+1 ), Point( 2, 2) );

    morphologyEx(in,close,MORPH_CLOSE,ele);
    imshow("CLOSE",close);

    waitKey(0);
    return 0;
}