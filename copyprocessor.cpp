#include "copyprocessor.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <QDebug>

#include <QThread>
#include "midiinput.h"

using namespace cv;
using namespace std;
using namespace drumstick::rt;

CopyProcessor::CopyProcessor() :
    midiOutput(0),
    face_cascade(),
    eyes_cascade(),
    currentFrame(0)
{
    QStringList outputConnections = midiOutput.connections(true);
    qDebug() << "MIDI Output Connections:";
    for (int i = 0; i < outputConnections.size(); ++i){
        qDebug() << outputConnections.at(i);
    }
    midiOutput.open("Microsoft GS Wavetable Synth");


    if( !face_cascade.load( "D:/Data/Uni/AVPRG/avprg-master/FaceHero/haarcascade_frontalface_alt.xml" ) ) {
        printf("--(!)Error loading face cascade\n");
    }

    if( !eyes_cascade.load( "D:/Data/Uni/AVPRG/avprg-master/FaceHero/haarcascade_eye_tree_eyeglasses.xml" ) ){
        printf("--(!)Error loading eyes cascade\n");
    }

    qDebug() << "cacades geladen";

}

// wird vor dem ersten Videoframe aufgerufen
void CopyProcessor::startProcessing(const VideoFormat& format){

}

// wird für jedes Videoframe aufgerufen
cv::Mat CopyProcessor::process(const cv::Mat&frame){
    std::vector<Rect> faces;
    Mat frame_gray;
    int sound = 0;
    if (currentFrame == 10) {

            cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
            qDebug() << "cvt";
            equalizeHist( frame_gray, frame_gray );
            qDebug() << "hist";

            //-- Detect faces
            face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
            qDebug() << "detect";

            for ( size_t i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
                ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

                Mat faceROI = frame_gray( faces[i] );
                std::vector<Rect> eyes;

                qDebug() << i << " gesicht";
                sound = i;

//                //-- In each face, detect eyes
//                eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

//                for ( size_t j = 0; j < eyes.size(); j++ )
//                {
//                    Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
//                    int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
//                    circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
//                    qDebug() << j << " augen";
//                }
            }
        currentFrame = 0;
        playSound(sound);
    } else {
        currentFrame++;
    }
    qDebug() << "fertig";
    return frame;
}

void CopyProcessor::playSound(int sound){
    // send MIDI Note On
    int channel = 0;
    int note;
    if (sound == 0) {
        note = 60;
    } else if (sound == 1) {
        note = 62;
    } else if (sound == 2) {
        note = 64;
    }

    int velocity = 127;
    midiOutput.sendNoteOn(channel, note, velocity);

    // wait 1 second
    QThread::sleep(1);

    // send MIDI Note Off
    midiOutput.sendNoteOff(channel, note, 0);
}
