#ifndef COPYPROCESSOR_H
#define COPYPROCESSOR_H

#include "videoprocessor.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace cv;

class CopyProcessor : public VideoProcessor
{

public:
    CopyProcessor();
    void startProcessing(const VideoFormat& format);
    Mat process(const cv::Mat&source);

};

#endif // COPYPROCESSOR_H
