#include <QFileDialog>
#include "facehero.h"
#include "ui_facehero.h"

FaceHero::FaceHero(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceHero)
    , videoThread(new VideoEngine)
    , copyProcessor(new CopyProcessor)
{
    ui->setupUi(this);
    videoThread->setProcessor(copyProcessor);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage,
            ui->processedFrame, &VideoWidget::setImage);
}

FaceHero::~FaceHero()
{
    delete videoThread;
    delete ui;
    delete copyProcessor;
}

void FaceHero::on_actionKamera_ffnen_triggered()
{
    videoThread->openCamera();
    videoThread->start();
}

