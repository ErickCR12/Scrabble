#ifndef CREATEGAMEWINDOW_H
#define CREATEGAMEWINDOW_H

#include <QDialog>
#include <socketcomunications/socketcliente.h>

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
    void on_acceptCreationButton_clicked();
    void on_cancelCreationButton_clicked();
    void printMensaje(QString msn);
    void sendMensaje();

private:
    SocketCliente *conexion;
    Ui::CreateGameWindow *ui;
};

#endif // CREATEGAMEWINDOW_H
