#include "client.h"
QT_USE_NAMESPACE

/** \~Italian
* @brief Costruttore di Client. Mi connetto al server.
* @param[QWidget *] parent
*/
Client::Client(QObject *parent) :
    QObject(parent)
{
   socket= new  QTcpSocket(this);
   socket->connectToHost("127.0.0.1", 1234); //mi connetto al server(ip e porta)
   connect(socket, SIGNAL(connected()),this,SLOT(onConnected())); //quando si connette esegue onConnect()
   connect(socket, SIGNAL(disconnected()),this,SLOT(onUnConnected()));
}

/** \~Italian
* @brief Slot eseguito quando il client si connette
*/
void Client::onConnected()
{
    qDebug()<<"Connesso al server...";
}

/** \~Italian
* @brief Slot eseguito quando il client si disconnette
*/
void Client::onUnConnected()
{
    message.setWindowTitle("Errore");
    message.setText("ATTENZIONE: Il client si è disconnesso");
    message.show();
    socket->deleteLater();
}

/** \~Italian
* @brief Invia al server la stringa, attende che arrivi correttamente, attnde che il server invia la risposta(la stringa contenente i coefficienti) e la leggo.
* @param[QString] pointsString: stringa contenente il grado, i coefficienti della x e della y dei punti inseriti dall'utente
*/
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

/** \~Italian
* @brief Decodifica la stringa inviata dal server ottenendo i coefficienti
* @return Un vettore contenente i coefficienti del polinomio di miglior approssimazione calcolati dal server
*/
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

/** \~Italian
* @brief Restituisce lo stato della connessione.
* @return True se è connesso, false altrimenti.
*/
bool Client::isConnected()
{
    if(socket->state()==0)
        return false;
    else
        return true;
}
