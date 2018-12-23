/*  Class object is used to access pixel information of an input matrix.
    Can be used by other classes to designate a ROI based around a selected seed-pixel.
*/ 
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <math.h>
#include <iostream>
#include <stdexcept>

#ifndef __CLICKFORPIXELDATA__
#define __CLICKFORPIXELDATA__




class ClickForPixelData
{
protected:

    /* I/O frame and window */
    cv::Mat *_input_frame;
    cv::Mat *_output_frame;
    cv::String display_window;

    /* Last known pixel HSV values */
    int H;
    int S;
    int V;

    /* Mouse-click event stuff */
    bool _mouse_clk;
    int _seed_x = 0;
    int _seed_y = 0; 

    /* Mouse event handling methods */
    static void onMouseEvt(int evt, int x, int y, int flags, void* ptr);
    int mouseEvent(int evt, int x, int y, int flags);

    int get_seed_pixel_hsv();

public:
    ClickForPixelData(cv::Mat *infrm, cv::Mat *outfrm, cv::String glugg_nafn);
    
};


#endif
