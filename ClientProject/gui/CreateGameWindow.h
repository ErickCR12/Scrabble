#ifndef CREATEGAMEWINDOW_H
#define CREATEGAMEWINDOW_H

#include <QDialog>
#include "socketcomunication/socketcliente.h"
#include "gui/ScrabbleWindow.h"
#include "json/ServerMessage.hpp"

namespace Ui {
class CreateGameWindow;
}

class CreateGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGameWindow(QWidget *parent = 0);
    ~CreateGameWindow();

private slots:
    void on_cancelCreationButton_clicked();
    void receiveMessage(QString msn);
    void sendMensaje();
private:
    Ui::CreateGameWindow *ui;
    SocketCliente *conexion;
    ScrabbleWindow *scrabbleWindow;
};

#endif // CREATEGAMEWINDOW_H
