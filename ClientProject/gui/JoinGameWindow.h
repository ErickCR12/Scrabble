#ifndef JOINGAMEWINDOW_H
#define JOINGAMEWINDOW_H

#include <QDialog>
#include <QTextStream>
#include <QMessageBox>
#include "socketcomunication/socketcliente.h"
#include "gui/ScrabbleWindow.h"
#include "json/ServerMessage.hpp"


namespace Ui {
class JoinGameWindow;
}
//! \brief The JoinGameWindow class serves as a QDialog for the mainWindow, where it gives the player
//! the choice to insert a gameCode of the game he wants to join.
class JoinGameWindow : public QDialog
{
    Q_OBJECT

public:
    //! \brief JoinGameWindow constructor. A Socket connection with the game server is created.
    //! \param parent: QWidget parent of this window.
    explicit JoinGameWindow(QWidget *parent = 0);
    ~JoinGameWindow();

private slots:

    //! \brief on_cancelCodeButton_clicked slot is signaled when user clicks cancelCodeButton.
    //! Destroys this window.
    void on_cancelCodeButton_clicked();
    //! \brief receiveMessage slot is signaled when the socket receives a message. Parse the msn to a
    //! JSON and manages it depending of the id.
    //! \param msn: Message received via socket.
    void receiveMessage(QString msn);
    //! \brief sendMensaje slot is signaled when acceptCodeButton is clicked. This function
    //! sends the server via socket the codeGame of the game that the user wants to join.
    void sendMensaje();

private:
    Ui::JoinGameWindow *ui;
    SocketCliente *conexion;
    ScrabbleWindow *scrabbleWindow;
};

#endif // JOINGAMEWINDOW_H
