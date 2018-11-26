#include "canny_thresh.hpp"


Mat canny_input_frame; Mat canny_output_frame;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

Mat src_gray;

void canny_thresh_callback(int, void* )
{
  Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( src_gray, canny_output, thresh, thresh*2, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }


}

void cvt_gray_and_blur()
{
   /// Convert image to gray and blur it
  cvtColor( canny_input_frame, src_gray, CV_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) ); 
}


void init_canny_trackbar()
{
  createTrackbar( "Canny thresh:", post_process_window, &thresh, max_thresh, canny_thresh_callback );
  canny_thresh_callback( 0, 0 );
}




