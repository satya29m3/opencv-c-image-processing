#include<opencv2/opencv.hpp>
 
using namespace cv;
 
int main( )
{
    Point2f inputQuad[4]; 
    Point2f outputQuad[4];
         
    Mat lambda( 2, 4, CV_32FC1 );
    
    Mat input, output;
     
    input = imread( "lena.jpg", 1 );
    lambda = Mat::zeros( input.rows, input.cols, input.type() );
 
    inputQuad[0] = Point2f( -30,-60 );
    inputQuad[1] = Point2f( input.cols+50,-50);
    inputQuad[2] = Point2f( input.cols+100,input.rows+50);
    inputQuad[3] = Point2f( -50,input.rows+50  );  
    
    outputQuad[0] = Point2f( 0,0 );
    outputQuad[1] = Point2f( input.cols-1,0);
    outputQuad[2] = Point2f( input.cols-1,input.rows-1);
    outputQuad[3] = Point2f( 0,input.rows-1  );
 
    // Get the Perspective Transform Matrix i.e. lambda 
    lambda = getPerspectiveTransform( inputQuad, outputQuad );
    // Apply the Perspective Transform just found to the src image
    warpPerspective(input,output,lambda,output.size() );
 
    imshow("Input",input);
    imshow("Output",output);
 
    waitKey(0);
    return 0;
}