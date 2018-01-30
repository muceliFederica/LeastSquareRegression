#ifndef PLOT_H
#define PLOT_H
#include <qwt_plot.h>
#include <qwt_symbol.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <Eigen/LU>
#include <Eigen/Dense>
#include <iostream>

using Eigen::MatrixXf;
using Eigen::VectorXf;
using namespace std;

class Plot : public QwtPlot
{
    public:
        Plot(QFrame *parent=0);
        ~Plot();
        void addPoint(const QPair<const int,const int> point);
        void deletePoints();
        QPair<std::vector<double>,std::vector<double>> findNeedPoint(std::vector<float> coeff,const int degree);
        void drawPlot(QPair<std::vector<double>,std::vector<double>> points,const int degree);

        int degree;
        std::vector<float> xCoords;
        std::vector<float> yCoords;
        std::vector<QwtPlotMarker*> marks;
};

#endif // PLOT_H
