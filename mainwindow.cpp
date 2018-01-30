#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qwt_plot.h>
#include <qwt_legend.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plot=new Plot(ui->framePlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
        plot->degree=ui->degreeSpinBox->value();
        ui->degreeSpinBox->hide();
    }
    ui->computeButton->setEnabled(true);
    ui->cleanButton->setEnabled(true);
}
void MainWindow::drawPlot(const QPair<std::vector<double>,std::vector<double>> points)
{
    if(regressionLine->isVisible())
        regressionLine->detach();

    regressionLine->setPen(QPen(Qt::darkGreen));
    regressionLine->setSamples(points.first.data(),points.second.data(),points.first.size());
    regressionLine->attach(plot);
    plot->replot();
}

void MainWindow::writeEquation(vector<float>coeffRegressionLine,int degree)
{
    float coeffRegressionLineTrunc;
    ui->equationInsertLabel->setText("\ny=");
    for(int i=degree;i>0;i--)
    {
        coeffRegressionLineTrunc=roundf(coeffRegressionLine.at(i)*100)/100;
        if (coeffRegressionLineTrunc>0)
            ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append("+"+QString::number(coeffRegressionLineTrunc)+"x^"+QString::number(i)));
        else if(coeffRegressionLineTrunc<0)
            ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append(QString::number(coeffRegressionLineTrunc)+"x^"+QString::number(i)));
    }

    coeffRegressionLineTrunc=roundf(coeffRegressionLine.at(0)*100)/100;
    if(coeffRegressionLineTrunc>0)
        ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append("+"+QString::number(coeffRegressionLineTrunc)));
    else if(coeffRegressionLineTrunc<0)
        ui->equationInsertLabel->setText(ui->equationInsertLabel->text().append(QString::number(coeffRegressionLineTrunc)));
}



void MainWindow::on_cleanButton_clicked()
{
    plot->degree=1;
    ui->degreeLabel->setText(QString("Grado: "));
    ui->degreeSpinBox->setVisible(true);
    ui->equationInsertLabel->setText(QString(""));
    plot->deletePoints();
    regressionLine->detach();
    ui->computeButton->setEnabled(false);
    ui->cleanButton->setEnabled(false);
    plot->replot();
}

void MainWindow::on_computeButton_clicked()
{
    LeastSquareRegressionLibrary regressionLine;
    std::vector<float> coeffRegressionLine=regressionLine.solveLinearSystem(plot->xCoords,plot->yCoords,plot->degree);
    writeEquation(coeffRegressionLine,plot->degree);
    QPair<std::vector<double>,std::vector<double>> points= plot->findNeedPoint(coeffRegressionLine,plot->degree);
    drawPlot(points);
}
