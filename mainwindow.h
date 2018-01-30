#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <plot.h>
#include <iostream>
#include <leastsquareregressionlibrary.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        void drawPlot(const QPair<std::vector<double>,std::vector<double>> points);
        ~MainWindow();

    private slots:
        void on_pushButton_clicked();

        void on_cleanButton_clicked();

        void on_computeButton_clicked();

    private:
        Ui::MainWindow *ui;
        Plot *plot;
        QwtPlotCurve *regressionLine=new QwtPlotCurve(QString(""));
        void writeEquation(const vector<float>coeffRegressionLine,const int degree);
};

#endif // MAINWINDOW_H
