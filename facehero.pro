#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T19:38:24
#
#-------------------------------------------------

QT       += core gui widgets



TARGET = facehero
TEMPLATE = app


SOURCES += main.cpp\
        facehero.cpp \
    copyprocessor.cpp

HEADERS  += facehero.h \
    copyprocessor.h

FORMS    += facehero.ui

include(../opencv/videoengine.pri)
include(../opencv/opencv.pri)


