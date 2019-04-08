#include "JoinGameWindow.h"
#include "ui_JoinGameWindow.h"
#include "gui/ScrabbleWindow.h"
#include <string>
#include <iostream>

JoinGameWindow::JoinGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinGameWindow)
{
    ui->setupUi(this);
    conexion = SocketCliente::getInstance();
    if(conexion->connectar()){
        connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(receiveMessage(QString)));
        connect(ui->insertCodeButton,SIGNAL(clicked()),SLOT(sendMensaje()));
    }else QMessageBox::critical(this,"Error","Error al conectar con el servidor",QMessageBox::Ok);
}

JoinGameWindow::~JoinGameWindow()
{
    delete ui;
}

void JoinGameWindow::on_cancelCodeButton_clicked()
{
    this->destroy();
}

void JoinGameWindow::sendMensaje()
{
    QString qCode = ui->codeLineEdit->text();
    conexion->sendMessage(qCode.toStdString().c_str());
}

void JoinGameWindow::receiveMessage(QString msn)
{
    if(scrabbleWindow)return;
    string json = msn.toStdString();
    ServerMessage *message = new ServerMessage();
    message = message->deserealize(json.c_str());
    switch (message->getId()) {
        case 2:{
            disconnect(conexion);
            scrabbleWindow = new ScrabbleWindow(this->parentWidget());
            scrabbleWindow->show();
            scrabbleWindow->createPlayerDeck(message->getLetterTiles());
            this->destroy();
            break;
        }default:
            break;
    }
}
