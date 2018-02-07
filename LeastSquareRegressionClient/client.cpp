#include "client.h"


QT_USE_NAMESPACE

Client::Client(QObject *parent) :
    QObject(parent)
{
   socket= new  QTcpSocket(this);
   socket->connectToHost("127.0.0.1", 1234); //mi connetto al server(ip e porta)

   connect(socket, SIGNAL(connected()),this,SLOT(onConnected())); //quando si connette esegue onConnect()
   connect(socket, SIGNAL(disconnected()),this,SLOT(onUnConnected()));
   qDebug()<<"Client partito...";
}

void Client::onConnected()
{
    qDebug()<<"Connesso al server...";
}

void Client::onUnConnected()
{
    qDebug()<<"Client Non Connesso...";
}

void Client::send(QString pointsString)
{
    data=pointsString.toLocal8Bit();
    qDebug()<<data.data();

    socket->write(data); //Mando al server quello che ho scritto
    socket->waitForBytesWritten();  //aspettando che arrivi correttamente.
    socket->flush();

    socket->waitForReadyRead(); //Aspetto che la risposta del server
    data=socket->readLine();    //sia disponibile e la leggo
    socket->flush();
}

std::vector<float> Client::getCoeffRegression()
{
    std::vector<float> coeffRegressionLine;
    QList<QByteArray> stringCoords=data.split('&');
    for(int i=0;i<stringCoords.size();i++)
    {
        coeffRegressionLine.push_back(stringCoords.at(i).toFloat());
    }
    return coeffRegressionLine;
}

bool Client::isConnected()
{
    if(socket->state()==0)
        return false;
    else
        return true;
}
