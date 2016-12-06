#ifndef COPYPROCESSOR_H
#define COPYPROCESSOR_H

#include "videoprocessor.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include "midiinput.h"

using namespace cv;
using namespace drumstick::rt;

class CopyProcessor : public VideoProcessor
{

public:
    CopyProcessor();
    void startProcessing(const VideoFormat& format);
    Mat process(const cv::Mat&source);
    void playSound(int sound);
    MIDIOutput midiOutput;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;

};

#endif // COPYPROCESSOR_H
