#include "mainwindow.h"
#include <QApplication>
#include <Eigen/Dense>
#include <qwt_plot.h>
#include <qwt_legend.h>
#include <Eigen/LU>
using Eigen::MatrixXd;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();

}
