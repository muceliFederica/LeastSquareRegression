#-------------------------------------------------
#
# Project created by QtCreator 2018-01-29T08:30:39
#
#-------------------------------------------------

QT       -= gui

TARGET = LeastSquareRegressionLibrary
TEMPLATE = lib

DEFINES += LEASTSQUAREREGRESSIONLIBRARY_LIBRARY

SOURCES += leastsquareregressionlibrary.cpp

HEADERS += leastsquareregressionlibrary.h\
        leastsquareregressionlibrary_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../eigen-eigen-5a0156e40feb/eigen-eigen-5a0156e40feb
