#ifndef JOINGAMEWINDOW_H
#define JOINGAMEWINDOW_H

#include <QDialog>
#include <QTextStream>
#include <QMessageBox>
#include "socketcomunication/socketcliente.h"
#include "gui/ScrabbleWindow.h"


namespace Ui {
class JoinGameWindow;
}

class JoinGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit JoinGameWindow(QWidget *parent = 0);
    ~JoinGameWindow();

private slots:

    void on_cancelCodeButton_clicked();
    void on_insertCodeButton_clicked();
    void printMensaje(QString msn);
    void sendMensaje();

private:
    Ui::JoinGameWindow *ui;
    SocketCliente *conexion;
    ScrabbleWindow *scrabbleWindow;
};

#endif // JOINGAMEWINDOW_H
