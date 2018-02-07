#-------------------------------------------------
#
# Project created by QtCreator 2018-01-23T12:52:22
#
#-------------------------------------------------

QT       += core gui
QT       += core websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RegressionLine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plot.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    plot.h \
    client.h

FORMS    += mainwindow.ui



INCLUDEPATH += $$PWD/Libs/eigen-eigen-5a0156e40feb/eigen-eigen-5a0156e40feb



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/LeastSquareRegressionLibrary/release/ -lLeastSquareRegressionLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/LeastSquareRegressionLibrary/debug/ -lLeastSquareRegressionLibrary
else:unix: LIBS += -L$$PWD/Libs/LeastSquareRegressionLibrary/ -lLeastSquareRegressionLibrary

INCLUDEPATH += $$PWD/Libs/LeastSquareRegressionLibrary
DEPENDPATH += $$PWD/Libs/LeastSquareRegressionLibrary

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/qwt-6.1.3/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/qwt-6.1.3/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/Libs/qwt-6.1.3/lib/ -lqwt

INCLUDEPATH += $$PWD/Libs/qwt-6.1.3/include
DEPENDPATH += $$PWD/Libs/qwt-6.1.3/include
