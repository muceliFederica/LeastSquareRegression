#include "databasemanager.h"
#include "ui_databasemanager.h"

/** \~Italian
* @brief Costruttore di DatabaseManager, setto la Ui e creo il dataset utilizzanod il driver QPSQL
* @param[QWidget *] parent
*/
DatabaseManager::DatabaseManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseManager)
{
    ui->setupUi(this);
    db = new QSqlDatabase( QSqlDatabase::addDatabase("QPSQL") );
}

/** \~Italian
* @brief Distruttore. Elimina la UI e l'istanza del database
*/
DatabaseManager::~DatabaseManager()
{
    delete ui;
    delete db;
}

/** \~Italian
* @brief Connessione al database. Prende in input i dati inseriti dall'utente
* @param[QString] server: hostname
* @param[QString] databaseName
* @param[QString] userName
* @param[QString] password
* @return QSqlDatabase accessibile
*/
QSqlDatabase* DatabaseManager::connect( const QString& server,const QString& databaseName,const QString& userName,const QString& password )
{
    db->setConnectOptions();
    db->setHostName(server);
    db->setDatabaseName(databaseName);
    db->setUserName(userName);
    db->setPassword(password);
    if(db->open()) {
        return db;
    }
    else {
        return NULL;
    }
}

/** \~Italian
* @brief Seleziona tutti i punti presenti nel database, nella tabella "points"
* @return Una coppia di vettori in cui rispettivamente troviamo le coordiante x e quelle y
*/
QPair< std::vector<float>,std::vector<float> > DatabaseManager::selectPoints()
{
    QSqlQuery* query = new QSqlQuery(*db);
    query->setForwardOnly(true);
    if( !query->prepare(QString("SELECT x,y from points")) )
    {
        message.setWindowTitle("Errore");
        message.setText(db->lastError().text());
        message.show();
        return   QPair<std::vector<float>,std::vector<float>> ();
    }
    else
    {
        bool queryRes = query->exec();
        if (query->lastError().type() != QSqlError::NoError || !queryRes)
        {
            message.setWindowTitle("Errore");
            message.setText(query->lastError().text());
            message.show();
        }

        std::vector<float> xCoords;
        std::vector<float> yCoords;
        while (query->next())
        {
            xCoords.push_back(query->value(0).toFloat());
            yCoords.push_back(query->value(1).toFloat());
        }
        QPair<std::vector<float>,std::vector<float>> records(xCoords,yCoords);
        return records;
    }
}

/** \~Italian
* @brief Slot eseguito quando si clicca nel pulsante OK. Si tenta la connessione al database, se la connesione va a buon fine,
* selezionati i punti dal database, viene  utilizzata la libreria LeastSquareRegressionLibrary per trovare i coefficienti del polinomio
* di miglior approssimazione. Plotto il grafico ottenuto
*/
void DatabaseManager::on_OkButton_clicked()
{
    connect( ui->hostLineEdit->text(),ui->databaseLineEdit->text(),ui->userLineEdit->text(),ui->passwordLineEdit->text() );
    if(db->open())
    {
        QPair<std::vector<float>,std::vector<float>> coords=selectPoints();
        for(unsigned int i=0;i<coords.first.size();i++)
        {
            plot->addPoint(QPair<float,float>(coords.first.at(i),coords.second.at(i)));
        }
        LeastSquareRegressionLibrary regressionLine;
        vector<float> coeffRegressionLine=regressionLine.solveLinearSystem(coords.first,coords.second,ui->degreeSpinBox->value());
        QPair<vector<double>,vector<double>> points= plot->findNeedPoint(coeffRegressionLine,ui->degreeSpinBox->value());
        plot->draw(points);
        plot->show();
        close();
    }
    else
    {
        message.setWindowTitle("Errore");
        message.setText("Attenzione: La connessione non è andata a buon fine.\nControllare i dati inseriti.");
        message.show();
    }
}

/** \~Italian
* @brief Slot eseguito quando si clicca nel pulsante Cancel. L'interfaccia della finestra di dilaogo viene reinizializzata
*/
void DatabaseManager::on_cancelButton_clicked()
{
    ui->setupUi(this);
}
