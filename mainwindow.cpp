#include "mainwindow.h"
#include "ui_mainwindow.h"

/** \~Italian
* @brief Costruttore della mainWindow. Crea il plot all'interno del framePlot
* @param[QWidget *] parent
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plot=new Plot(ui->framePlot);
}

/** \~Italian
* @brief Distruttore. Distrugge anche il plot
*/
MainWindow::~MainWindow()
{
    plot->~Plot();
    delete ui;
}

/** \~Italian
* @brief Slot eseguito quando viene aggiunto un nuovo punto. Reinizializzazione e aggiornamento UI
*/
void MainWindow::on_pushButton_clicked()
{
    QPair<int,int> point;
    point.first=ui->xSpinBox->value();
    point.second=ui->ySpinBox->value();
    plot->addPoint(point);

    ui->xSpinBox->setValue(0);
    ui->ySpinBox->setValue(0);
    ui->degreeLabel->setText(QString("Il grado selezionato è ").append(QString::number(ui->degreeSpinBox->value())));
    if(!ui->degreeSpinBox->isHidden())
    {
        plot->setDegree(ui->degreeSpinBox->value());
        ui->degreeSpinBox->hide();
    }
    ui->computeButton->setEnabled(true);
    ui->cleanButton->setEnabled(true);
}



/** \~Italian
* @brief Costruisce l'equazione e la mostra in UI
* @param[vector<float>]coeffRegressionLine: vettore contenente i coefficienti del polinomio
* @param[int] degree: grado del polinomio
*/
void MainWindow::writeEquation(vector<float>coeffRegressionLine,int degree)
{
    float coeffRegressionLineTrunc;
    ui->equationInsertLabel->setText("\ny=");
    for(int i=degree;i>0;i--)
    {
        //Tronco il float alla seconda cifra decimale
        coeffRegressionLineTrunc=roundf(coeffRegressionLine.at(i)*1000)/1000;
        if (coeffRegressionLineTrunc>0)
            ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append("+"+QString::number(coeffRegressionLineTrunc)+"x^"+QString::number(i)));
        else if(coeffRegressionLineTrunc<0)
            ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append(QString::number(coeffRegressionLineTrunc)+"x^"+QString::number(i)));
    }

    coeffRegressionLineTrunc=roundf(coeffRegressionLine.at(0)*1000)/1000;
    if(coeffRegressionLineTrunc>0)
        ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append("+"+QString::number(coeffRegressionLineTrunc)));
    else if(coeffRegressionLineTrunc<0)
        ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append(QString::number(coeffRegressionLineTrunc)));
    else
        ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append("+0"));
}

/** \~Italian
* @brief Slot utilizzato per ripulire l'ambiente. Reinizializza il plot e UI
*/
void MainWindow::on_cleanButton_clicked()
{
    plot->clearPlot();
    plot->setDegree(1);
    ui->degreeLabel->setText(QString("Grado: "));
    ui->degreeSpinBox->setVisible(true);
    ui->equationInsertLabel->setText(QString(""));
    ui->computeButton->setEnabled(false);
    ui->cleanButton->setEnabled(false);
    plot->replot();
}


/** \~Italian
* @brief Slot che esegue l'approssimazione ai minimi quadrati. Utilizza la libreria "LeastSquareRegressionLibrary"
*/
void MainWindow::on_computeButton_clicked()
{
    LeastSquareRegressionLibrary regressionLine;
    vector<float> coeffRegressionLine=regressionLine.solveLinearSystem(plot->getXCoords(),plot->getYCoords(),plot->getDegree());
    writeEquation(coeffRegressionLine,plot->getDegree());
    QPair<vector<double>,vector<double>> points= plot->findNeedPoint(coeffRegressionLine,plot->getDegree());
    plot->draw(points);
}
