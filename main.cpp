#include "facehero.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaceHero w;
    w.show();

    w.on_actionKamera_ffnen_triggered();
    return a.exec();
}
