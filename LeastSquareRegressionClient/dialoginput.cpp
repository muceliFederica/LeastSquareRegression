#include "dialoginput.h"
#include "ui_dialoginput.h"

/** \~Italian
* @brief Costruttore di DialogInput.
* @param[QWidget *] parent
*/
DialogInput::DialogInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInput)
{
    ui->setupUi(this);
}

/** \~Italian
* @brief Distruttore.
*/
DialogInput::~DialogInput()
{
    delete ui;
}

/** \~Italian
* @brief Slot che, in base al radiobutton selezionato dall'utente crea la finestra corrispondente e setta il Type
*/
void DialogInput::on_okPushButton_clicked()
{
    if(ui->tastieraRadioButton->isChecked())
    {
        w.setType(1);
        w.showMaximized();
    }
    else if (ui->serverRadioButton->isChecked())
    {
        w.setType(2);
        w.showMaximized();
    }
    else if(ui->databaseRadioButton->isChecked())
    {
        w.setType(3);
        databaseManager.show();
    }
}

/** \~Italian
* @brief Slot che chiude la finestra quando viene cliccato il pulsante Close
*/
void DialogInput::on_closePushButton_clicked()
{
    close();
}
