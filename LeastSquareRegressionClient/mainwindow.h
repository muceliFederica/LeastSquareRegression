#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <plot.h>
#include <leastsquareregressionlibrary.h>
#include <iostream>
#include <client.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        void drawPlot(const QPair<vector<double>,vector<double>> points);
        ~MainWindow();
        void setType(int type);
        int getType();

    private slots:

        void on_cleanButton_clicked();

        void on_computeButton_clicked();

        void on_addPointPushButton_clicked();

private:
        Ui::MainWindow *ui;
        Plot *plot;
        Client client;
        QMessageBox message;
        int type; //1 tastiera(no server), 2 server, 3 database
        void writeEquation(const vector<float>coeffRegressionLine,const int degree);

};

#endif // MAINWINDOW_H
