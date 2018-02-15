#ifndef PLOT_H
#define PLOT_H
#include <qwt_plot.h>
#include <qwt_symbol.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>

using namespace std;

class Plot : public QwtPlot
{
    public:
        Plot(QFrame *parent=0);
        void addPoint(const QPair<const float,const float> point);
        void clearPlot();
        QPair<vector<double>,vector<double>> findNeedPoint(vector<float> coeff,const int degree);
        void draw(const QPair<vector<double>,vector<double>> points);
        void setDegree(int degree);
        int getDegree();
        void setXCoord(float x);
        vector<float> getXCoords();
        void setYCoord(float y);
        vector<float> getYCoords();
        void setMark(QwtPlotMarker* mark);
        vector<QwtPlotMarker*> getMarks();

    private:
        QwtPlotCurve *regressionLine=new QwtPlotCurve(QString(""));
        int degree;
        vector<float> xCoords;
        vector<float> yCoords;
        vector<QwtPlotMarker*> marks;//Vettore che conserva i marcatori presenti nel grafico
};

#endif // PLOT_H
