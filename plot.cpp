#include "plot.h"

/*Costruttore del plot
**Inizializza sfondo, assi e dimensioni del Plot
*/
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

/*Distruttore*/
Plot::~Plot()
{
    delete this;
}

/*Aggiunge un punto(marker) al grafico
**Il marker è caratterizzato da delle coordinate, un simbolo e una label
*/
void Plot::addPoint(const QPair<const int,const int> point)
{
    xCoords.push_back(point.first);
    yCoords.push_back(point.second);
    QwtPlotMarker *mark=new QwtPlotMarker;
    QwtSymbol *sym=new QwtSymbol(QwtSymbol::Ellipse,QBrush(Qt::red),QPen(Qt::red),QSize(7,7));
    mark->setSymbol(sym);
    mark->setValue(point.first,point.second);
    QwtText label("("+QString::number(point.first)+","+QString::number(point.second)+")");
    label.setFont(QFont("MS Reference Sans Serif",6));
    mark->setLabel(label);
    mark->setLabelAlignment(Qt::AlignTop);
    mark->attach(this);
    marks.push_back(mark);
    replot();
}

/*Elimino i marker dal grafico.
**Ripulisco i vettori contenenti i punti inseriti
*/
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

/*Individua i punti necessari per disegnare il grafico*/
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

void Plot::setDegree(int degree)
{
    this->degree=degree;
}

int Plot::getDegree()
{
    return degree;
}

void Plot::setXCoord(float x)
{
    xCoords.push_back(x);
}

std::vector<float> Plot::getXCoords()
{
    return xCoords;
}

void Plot::setYCoord(float y)
{
    yCoords.push_back(y);
}

std::vector<float> Plot::getYCoords()
{
    return yCoords;
}

void Plot::setMark(QwtPlotMarker* mark)
{
    marks.push_back(mark);
}

std::vector<QwtPlotMarker*> Plot::getMarks()
{
    return marks;
}
