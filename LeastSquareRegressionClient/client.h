#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <iostream>
#include <regex>

class Client : public QObject
{
    Q_OBJECT
    public:
        explicit Client(QObject *parent = 0);
        std::vector<float> getCoeffRegression();
        void send(QString pointsString);
        bool isConnected();

    signals:

    public slots:
        void onUnConnected();
        void onConnected();

    private:
        QTcpSocket *socket; //socket utilizzato per la connessione
        QByteArray data; //array per scambiare messaggi con il server

};


#endif // CLIENT_H
