#-------------------------------------------------
#
# Project created by QtCreator 2018-02-06T10:35:07
#
#-------------------------------------------------

QT       += core websockets
QT       -= gui

TARGET = server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    server.cpp

HEADERS += \
    server.h


INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/LeastSquareRegressionLibrary/release/ -lLeastSquareRegressionLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/LeastSquareRegressionLibrary/debug/ -lLeastSquareRegressionLibrary
else:unix: LIBS += -L$$PWD/Libs/LeastSquareRegressionLibrary/ -lLeastSquareRegressionLibrary

INCLUDEPATH += $$PWD/Libs/LeastSquareRegressionLibrary
DEPENDPATH += $$PWD/Libs/LeastSquareRegressionLibrary
INCLUDEPATH += $$PWD/Libs/eigen-eigen-5a0156e40feb/eigen-eigen-5a0156e40feb
