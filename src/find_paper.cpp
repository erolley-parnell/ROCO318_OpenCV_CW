// testPFC.cpp : This file contains the 'main' function. Program execution begins and ends there.
// the contours2.cpp samplke c++ code is reproduced here
// RUN and adjust slider
// Understand how it works.

#include "find_paper.hpp"

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <math.h>
#include <iostream>

using namespace cv;
using namespace std;

Mat input_frame;
Mat output_frame;
char pre_process_window[16]  = "Preprocess";
char post_process_window[16] = "Postprocess";


/* Some reference code: https://raw.githubusercontent.com/kylehounslow/opencv-tuts/master/object-tracking-tut/objectTrackingTut.cpp */
/* From here: https://www.youtube.com/watch?v=bSeFrPrqZ2A */
int main(int, char **)
{
    VideoCapture cap(0); // open the default camera
    if (!cap.isOpened()) // check if we succeeded and return -1 if not
    {
        return -1;
    }    

    /* Initializing viewing windows */   
    namedWindow(pre_process_window);
    namedWindow(post_process_window);

    /* initiaalize HSV thresholding trackbars, 
    and set the mouse-click callback for sniffing pixel info*/
    init_HSV_trackbars(); 
    setMouseCallback(pre_process_window, mouseEvent, &input_frame); 

    while(1)
    {
        cap >> input_frame; // get a new frame from video capture and store in matrix frame.
        imshow(pre_process_window, input_frame); //show the captured frame in the relevant display window.


       run_HSV_thresh();

        if (waitKey(30) >= 0)
        {
            destroyAllWindows();
            break;
        }   
    }
    
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
