#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include "dialoginput.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogInput dialogInput;
    dialogInput.show();
    return a.exec();
}
