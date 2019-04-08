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
    conexion = new SocketCliente;
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
    QTextStream out(stdout);
    out << "AAAAAAAA\n";
    foreach(QString x, msn){
        out << x;
    }out<<"\n";

    string json = msn.toStdString();
    ServerMessage *message = new ServerMessage();
    message = message->deserealize(json.c_str());
    out << QString::fromStdString(to_string(message->getId()) + "\n");
    switch (message->getId()) {
        case 2:{
            scrabbleWindow = new ScrabbleWindow(this->parentWidget());
            scrabbleWindow->setConexion(conexion);
            scrabbleWindow->show();
            scrabbleWindow->createPlayerDeck(message->getLetterTiles());
            this->destroy();
            break;
        }case 3:
            out << "CASE3\n";
            break;
        default:
            break;
    }
}
