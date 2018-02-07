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

class Server : public QObject
{
    Q_OBJECT
   public:
       explicit Server(QObject *parent = 0);
        vector<float> findXCoords(QByteArray mykeypass);
        vector<float> findYCoords(QByteArray mykeypass);
        int findDegree(QByteArray mykeypass);
   signals:


   public slots:
       void newConnection();


   private:
       QTcpServer *server;
};

#endif // SERVER_H
