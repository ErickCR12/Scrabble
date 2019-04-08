#ifndef CREATEGAMEWINDOW_H
#define CREATEGAMEWINDOW_H

#include <QDialog>
#include "socketcomunication/socketcliente.h"
#include "gui/ScrabbleWindow.h"
#include "json/ServerMessage.hpp"

namespace Ui {
class CreateGameWindow;
}

//! \brief The CreateGameWindow class serves as a QDialog for the mainWindow, where it gives the player
//! the choice to createa a new game with the amount of players specified.
class CreateGameWindow : public QDialog
{
    Q_OBJECT

public:
    //! \brief CreateGameWindow constructor. A Socket connection with the game server is created.
    //! \param parent: QWidget parent of this window.
    explicit CreateGameWindow(QWidget *parent = 0);

    ~CreateGameWindow();

private slots:

    //! \brief on_cancelCreationButton_clicked slot is signaled when user clicks cancelCreationButton.
    //! Destroys this window.
    void on_cancelCreationButton_clicked();
    //! \brief receiveMessage slot is signaled when the socket receives a message. Parse the msn to a
    //! JSON and manages it depending of the id.
    //! \param msn: Message received via socket.
    void receiveMessage(QString msn);
    //! \brief sendMensaje slot is signaled when acceptCreationButton is clicked. This function
    //! sends the server via socket the maxi amount of players for the game created.
    void sendMensaje();
private:
    Ui::CreateGameWindow *ui;
    SocketCliente *conexion;
    ScrabbleWindow *scrabbleWindow;
};

#endif // CREATEGAMEWINDOW_H
