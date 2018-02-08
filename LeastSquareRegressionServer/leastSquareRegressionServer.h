#ifndef SERVER_H
#define SERVER_H

#include "leastsquareregressionlibrary.h"
#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QByteArray> //only for QByteArray object
#include <QTime>
#include <QCoreApplication>
#include <QTcpSocket>



QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class leastSquareRegressionServer : public QObject
{
    Q_OBJECT
   public:
       explicit leastSquareRegressionServer(QObject *parent = 0);
        vector<float> findXCoords(QByteArray mykeypass);
        vector<float> findYCoords(QByteArray mykeypass);
        int findDegree(QByteArray mykeypass);
        void myRead(QTcpSocket* socket);
   signals:


   public slots:
       void newConnection();
       void disconnected();

   private:
       QTcpServer *server;
       bool connected=false;
};

#endif // SERVER_H
