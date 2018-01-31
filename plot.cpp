#include "plot.h"

/** \~Italian
* @brief Costruttore, crea un plot e assi e dimensioni
* @param[QFrame*] parent: Frame che conterrà il plot
*/
Plot::Plot(QFrame *parent): QwtPlot(parent)
{
    QwtText xTitle("Tempo");
    xTitle.setFont(QFont("Palatino Linotype",13,QFont::Bold,QFont::StyleItalic));
    setAxisTitle(QwtPlot::xBottom,xTitle);
    QwtText yTitle("Valori Dipendenti");
    yTitle.setFont(QFont("Palatino Linotype",13,QFont::Bold,QFont::StyleItalic));
    setAxisTitle(QwtPlot::yLeft,yTitle);
    setAxisFont(QwtPlot::yLeft,QFont("MS Reference Sans Serif",8,QFont::Bold) );
    setAxisFont(QwtPlot::xBottom,QFont("MS Reference Sans Serif",8,QFont::Bold) );
    axisTitle(QwtPlot::yLeft).setFont(QFont("MS Reference Sans Serif",15));
    setAxisScale(QwtPlot::yLeft,0,1000.0);
    setAxisScale(QwtPlot::xBottom, 0,1000.0);
    resize(700,450);
}

/** \~Italian
* @brief Distruttore
*/
Plot::~Plot()
{
    delete this;
}


/** \~Italian
* @brief Aggiunge un punto(marker) al grafico
* @param[QPair<const int,const int>] point: coppia che contiene le coordiante del nuovo punto
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


/** \~Italian
* @brief Elimino la curva dal grafico, distrugge tutti i marker dal grafico e ripulisce i vettori contenenti i punti inseriti.
*/
void Plot::clearPlot()
{
    regressionLine->detach();
    for(unsigned int i=0;i<marks.size();i++)
    {
        QwtPlotMarker* mark=marks.at(i);
        mark->~QwtPlotMarker();
    }
    xCoords.clear();
    yCoords.clear();
    marks.clear();
}

/** \~Italian
* @brief Inserisce nel plot la curva QwtPlotCurve
* @param[const QPair<vector<double>,vector<double>>] points: coppia di vettori contenenti le coordinate X e Y dei punti necessari per disegnare il grafico
*/
void Plot::draw(const QPair<vector<double>,vector<double>> points)
{
    if(regressionLine->isVisible())
        regressionLine->detach();

    regressionLine->setPen(QPen(Qt::blue,2.0));
    regressionLine->setSamples(points.first.data(),points.second.data(),points.first.size());
    regressionLine->attach(this);
    replot();
}

/** \~Italian
* @brief Individua i punti necessari per disegnare il grafico
* @param[vector<float] coeff: vettore contenente i coefficienti del polinomio trovati con il metodo dei minimi quadrati
* @param[int] degree: grado del polinomio insserito dall'utente
* @return una coppia QPair di vettori di double, nel primo vettore sono contenute le coordinate x dei punti, nel secondo le coordinate y
*/
QPair<vector<double>,vector<double>> Plot::findNeedPoint(vector<float> coeff,int degree)
{
    QPair<vector<double>,vector<double>> points;
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

/** \~Italian
* @brief Setta il grado inserito
* @param[int] degree
*/
void Plot::setDegree(int degree)
{
    this->degree=degree;
}
/** \~Italian
* @brief Restituisce il valore del grado
* @return il grado
*/
int Plot::getDegree()
{
    return degree;
}

/** \~Italian
* @brief Inserisce nel vettore xCoords un nuovo valore
* @param[float] x: coordianata x di un nuovo punto
*/
void Plot::setXCoord(float x)
{
    xCoords.push_back(x);
}

/** \~Italian
* @brief Restituisce il vettore xCoords
* @return il vettore contenente le coordinate x di tutti i punti inseriti in input
*/
vector<float> Plot::getXCoords()
{
    return xCoords;
}

/** \~Italian
* @brief Inserisce nel vettore yCoords un nuovo valore
* @param[float] y: coordianata y di un nuovo punto
*/
void Plot::setYCoord(float y)
{
    yCoords.push_back(y);
}

/** \~Italian
* @brief Restituisce il vettore yCoords
* @return il vettore contenente le coordinate y di tutti i punti inseriti in input
*/
vector<float> Plot::getYCoords()
{
    return yCoords;
}

/** \~Italian
* @brief Inserisce nel vettore marks un nuovo QwtPlotMarker*
* @param[QwtPlotMarker*] mark: un nuovo marcatore inserito nel grafico
*/
void Plot::setMark(QwtPlotMarker* mark)
{
    marks.push_back(mark);
}

/** \~Italian
* @brief Restituisce il vettore marks
* @return il vettore contenente tutti i marcatori inseriti nel grafico
*/
vector<QwtPlotMarker*> Plot::getMarks()
{
    return marks;
}
