#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    return a.exec();
}
