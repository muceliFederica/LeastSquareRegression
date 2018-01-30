#include "plot.h"

Plot::Plot(QFrame *parent): QwtPlot(parent)
{
    setCanvasBackground(Qt::white);
    QwtText xTitle("Tempo");
    xTitle.setFont(QFont("Palatino Linotype",13,QFont::Bold,QFont::StyleItalic));
    setAxisTitle(QwtPlot::xBottom,xTitle);
    QwtText yTitle("Valori Dipendenti");
    yTitle.setFont(QFont("Palatino Linotype",13,QFont::Bold,QFont::StyleItalic));
    setAxisTitle(QwtPlot::yLeft,yTitle);
    setAxisFont(QwtPlot::yLeft,QFont("MS Reference Sans Serif",8,QFont::Bold) );
    setAxisFont(QwtPlot::xBottom,QFont("MS Reference Sans Serif",8,QFont::Bold) );
    axisTitle(QwtPlot::yLeft).setFont(QFont("MS Reference Sans Serif",15));
    setAxisAutoScale(QwtPlot::yLeft, true);
    setAxisAutoScale(QwtPlot::xBottom, true);
    resize(700,450);

}
Plot::~Plot()
{
    delete this;
}

void Plot::addPoint(const QPair<const int,const int> point)
{
    QwtSymbol *sym=new QwtSymbol(QwtSymbol::Diamond,QBrush(Qt::red),QPen(Qt::red),QSize(5,5));
    xCoords.push_back(point.first);
    yCoords.push_back(point.second);
    QwtPlotMarker *mark=new QwtPlotMarker;
    mark->setSymbol(sym);
    mark->setValue(point.first,point.second);
    mark->attach(this);
    marks.push_back(mark);
    replot();
}

void Plot::deletePoints()
{
    for(unsigned int i=0;i<marks.size();i++)
    {
        QwtPlotMarker* mark=marks.at(i);
        mark->detach();
    }
    xCoords.clear();
    yCoords.clear();
    marks.clear();

}

QPair<std::vector<double>,std::vector<double>> Plot::findNeedPoint(std::vector<float> coeff,int degree)
{
    QPair<std::vector<double>,std::vector<double>> points;
    switch(degree)
    {
        case 1:

            //Per la retta mi bastano 2 punti
            points.first.push_back(1.0);
            points.second.push_back(1.0*coeff.at(1)+coeff.at(0));
            points.first.push_back(1000.0);
            points.second.push_back(1000.0*coeff.at(1)+coeff.at(0));

        break;

        default:

            for(int x=0; x<1000;x=x+10)
            {
                int y=0;
                points.first.push_back(x);
                for(int i=degree;i>=0;i--)
                {
                    y=y+coeff.at(i)*pow(x,i);
                }
                points.second.push_back(y);
            }
        break;
    }

    return points;
}
