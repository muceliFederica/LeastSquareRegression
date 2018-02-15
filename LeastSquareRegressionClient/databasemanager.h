#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QDialog>

#include <QtSql>
#include <QString>
#include <QDebug>
#include "mainwindow.h"
#include "qmessagebox.h"

namespace Ui {
class DatabaseManager;
}

class DatabaseManager : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseManager(QWidget *parent = 0);
    ~DatabaseManager();
    QSqlDatabase* connect( const QString& server,
                           const QString& databaseName,
                           const QString& userName,
                           const QString& password );
    void disConnect();

    QPair< std::vector<float>,std::vector<float> > selectPoints();

private slots:
    void on_OkButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DatabaseManager *ui;
    QSqlDatabase* db;
    Plot* plot=new Plot();
    QMessageBox message;

};

#endif // DATABASEMANAGER_H
