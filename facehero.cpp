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

void FaceHero::on_actionVideodatei_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }
}

void FaceHero::on_actionKamera_ffnen_triggered()
{
    videoThread->openCamera();
}

void FaceHero::on_actionPlay_triggered()
{
    videoThread->start();
}
