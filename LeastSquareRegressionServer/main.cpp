#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include "leastSquareRegressionServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    leastSquareRegressionServer server;

    return a.exec();
}
