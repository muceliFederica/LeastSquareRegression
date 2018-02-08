#include "leastSquareRegressionServer.h"

leastSquareRegressionServer::leastSquareRegressionServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),this, SLOT(newConnection()) ); //non appena arrivano nuove connessioni esegue newConnection()

    if (!server->listen(QHostAddress::Any, 1234)) //mette in ascolto il leastSquareRegressionServer sulla porta 1234 se possibile
    {
        qDebug()<< "Il Server non puo' partire.";

    }else{
        qDebug()<< "Server partito.";
    }
}


void leastSquareRegressionServer::newConnection()
{
    connected=true;
    qDebug()<<"newConnection";
    QTcpSocket* socket=server->nextPendingConnection(); // "Aggancio" il socket al Server (bind)
    myRead(socket);
}

void leastSquareRegressionServer::myRead(QTcpSocket* socket)
{
    socket->flush();
    QByteArray mykeypass; //Array di byte utilizzato per scambiare dati con il client

    while(connected==true)
    {

        if (socket->waitForReadyRead(3000)) //aspetto che venga emesso nel client il segnale readyRead()
        {
            //Leggo e mostro cosa ha scritto il client
            mykeypass=socket->readAll();

            qDebug()<<"<INPUT CLIENT>"<< mykeypass;
            socket->flush();

            LeastSquareRegressionLibrary regressionLine;
            vector<float> coeff=regressionLine.solveLinearSystem(findXCoords(mykeypass),findYCoords(mykeypass),findDegree(mykeypass));
            mykeypass.clear();
            mykeypass.append(QString::number(coeff.at(0)));
            for(unsigned int i=1;i<coeff.size();i++)
            {
                mykeypass.append(QString("&").append(QString::number(coeff.at(i))));
            }
            qDebug()<<"<OUTPUT Server>"<<mykeypass;
            socket->write(mykeypass);
            socket->flush();
            connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));

        }
    }

}

void leastSquareRegressionServer::disconnected()
{
    qDebug()<<"Disconnected";
    connected=false;

}

vector<float> leastSquareRegressionServer::findXCoords(QByteArray mykeypass)
{
    vector<float> xCoords;

    int maxIndex=mykeypass.indexOf('?');
    mykeypass.truncate(maxIndex);
    QList<QByteArray> stringCoords=mykeypass.split('&');
    for(int i=1;i<stringCoords.size();i++)
    {
        xCoords.push_back(stringCoords.at(i).toInt());
    }
    return xCoords;
}

vector<float> leastSquareRegressionServer::findYCoords(QByteArray mykeypass)
{
    vector<float> yCoords;

    int minIndex=mykeypass.indexOf('?');
    mykeypass=mykeypass.right(mykeypass.length()-minIndex);
    QList<QByteArray> stringCoords=mykeypass.split('?');
    for(int i=1;i<stringCoords.size();i++)
    {
        yCoords.push_back(stringCoords.at(i).toInt());
    }

    return yCoords;
}

int leastSquareRegressionServer::findDegree(QByteArray mykeypass)
{

    return mykeypass.at(0)-'0';
}
