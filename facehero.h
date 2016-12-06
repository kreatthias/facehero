#ifndef FACEHERO_H
#define FACEHERO_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "copyprocessor.h"

namespace Ui {
class FaceHero;
}

class FaceHero : public QMainWindow
{
    Q_OBJECT

public:
    explicit FaceHero(QWidget *parent = 0);
    ~FaceHero();
    void on_actionKamera_ffnen_triggered();

private:
    Ui::FaceHero *ui;
    VideoEngine *videoThread;
    CopyProcessor *copyProcessor;
};

#endif // FACEHERO_H
