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

void JoinGameWindow::on_insertCodeButton_clicked()
{
//    QString qCode = ui->codeLineEdit->text();
//    string strCode = qCode.toStdString();
//    cout << strCode << endl;
//    this->destroy();
//    ScrabbleWindow scrabble;
//    scrabble.setModal(true);
//    scrabble.exec();
}

void JoinGameWindow::sendMensaje()
{
    QString qCode = ui->codeLineEdit->text();
    conexion->setMensaje(qCode.toStdString().c_str());
}

void JoinGameWindow::receiveMessage(QString msn)
{
    QTextStream out(stdout);
    foreach(QString x, msn){
        out << x;
    }out<<"\n";

    string json = msn.toStdString();
    ServerMessage *message = new ServerMessage();
    message = message->deserealize(json.c_str());
    scrabbleWindow = new ScrabbleWindow(this->parentWidget());
    scrabbleWindow->setConexion(conexion);
    scrabbleWindow->show();
    scrabbleWindow->createPlayerDeck(message->getLetterTiles());
    this->destroy();
}
