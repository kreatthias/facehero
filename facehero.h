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

private slots:
    void on_actionVideodatei_ffnen_triggered();
    void on_actionKamera_ffnen_triggered();
    void on_actionPlay_triggered();
private:
    Ui::FaceHero *ui;
    VideoEngine *videoThread;
    CopyProcessor *copyProcessor;
};

#endif // FACEHERO_H
