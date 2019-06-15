#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

Mat in,blur_img;
Mat out,edge;

int main(){

    in  = imread("im.jpg",IMREAD_GRAYSCALE);
    GaussianBlur(in,blur_img,Size(5,5),0); 
    Canny(blur_img,edge,50,250,5);
    imshow("edge detection",edge);
    waitKey(0);
    return(0);
}







