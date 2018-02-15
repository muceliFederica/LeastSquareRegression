#ifndef DIALOGINPUT_H
#define DIALOGINPUT_H

#include <QDialog>
#include "mainwindow.h"
#include "databasemanager.h"
namespace Ui {
class DialogInput;
}

class DialogInput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInput(QWidget *parent = 0);
    ~DialogInput();

private slots:

    void on_okPushButton_clicked();

    void on_closePushButton_clicked();

private:
    Ui::DialogInput *ui;
    MainWindow w;
    DatabaseManager databaseManager;
};

#endif // DIALOGINPUT_H
