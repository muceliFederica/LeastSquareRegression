#include "server.h"

Server::Server(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),this, SLOT(newConnection()) ); //non appena arrivano nuove connessioni esegue newConnection()


    if (!server->listen(QHostAddress::Any, 1234)) //mette in ascolto il server sulla porta 1234 se possibile
    {
        qDebug()<< "Il Server non puo' partire.";

    }else{
        qDebug()<< "Server partito.";
    }
}


void Server::newConnection()
{
    QTcpSocket *socket=server->nextPendingConnection(); // "Aggancio" il socket al server (bind)
    socket->flush();

    QByteArray mykeypass; //Array di byte utilizzato per scambiare dati con il client
    bool quit=false;      //una varibile booleana per uscire dal while
    while(quit==false)
    {

        if (socket->waitForReadyRead(3000)) //aspetto che venga emesso nel client il segnale readyRead()
        {
            mykeypass.clear();
            //Leggo e mostro cosa ha scritto il client
            mykeypass=socket->readLine();

            qDebug()<<"<CLIENT>"<< mykeypass;
            socket->flush();

            LeastSquareRegressionLibrary regressionLine;
            vector<float> coeff=regressionLine.solveLinearSystem(findXCoords(mykeypass),findYCoords(mykeypass),findDegree(mykeypass));
            mykeypass.clear();
            mykeypass.append(QString::number(coeff.at(0)));
            for(unsigned int i=1;i<coeff.size();i++)
            {
                mykeypass.append(QString("&").append(QString::number(coeff.at(i))));
            }
            qDebug()<<mykeypass;
            //Invio al client l'eco di quello che ha scritto
            socket->write(mykeypass);
            socket->flush();
        }
        if (strcmp(mykeypass.data(),"quit")==0) //Mi serve solo per uscire dal programma
        {
            quit=true; qDebug()<<"Esco...";
            socket->close();
            qApp->exit();
        }

    }
}

vector<float> Server::findXCoords(QByteArray mykeypass)
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

vector<float> Server::findYCoords(QByteArray mykeypass)
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

int Server::findDegree(QByteArray mykeypass)
{

    return mykeypass.at(0)-'0';
}
