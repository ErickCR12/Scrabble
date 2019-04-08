#include "CreateGameWindow.h"
#include "ui_CreateGameWindow.h"
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>

using namespace std;
CreateGameWindow::CreateGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGameWindow)
{
    ui->setupUi(this);
    ui->amountOfPlayersComboBox->addItems({"2", "3", "4"});
    conexion = new SocketCliente;
    if(conexion->connectar()){
        this->show();
        connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(receiveMessage(QString)));
        connect(ui->acceptCreationButton,SIGNAL(clicked()),SLOT(sendMensaje()));
    }else QMessageBox::critical(this,"Error","Error al conectar con el servidor",QMessageBox::Ok);
}

CreateGameWindow::~CreateGameWindow()
{
    delete ui;
}

void CreateGameWindow::on_cancelCreationButton_clicked()
{
    this->destroy();
}


void CreateGameWindow::sendMensaje()
{
    QString qAmount = ui->amountOfPlayersComboBox->currentText();
    ui->amountOfPlayersComboBox->setDisabled(true);
    conexion->sendMessage(qAmount.toStdString().c_str());
}

void CreateGameWindow::receiveMessage(QString msn)
{
    QTextStream out(stdout);
    out << "CCCCCCCC\n";
    foreach(QString x, msn){
        out << x;
    }out<<"\n";

    string json = msn.toStdString();
    ServerMessage *message = new ServerMessage();
    message->deserealize(json.c_str());
    message = message->deserealize(json.c_str());
    out << QString::fromStdString(to_string(message->getId()) + "\n");
    switch(message->getId()){
        case 1:{
            string lblStr = "Tu código de juego es: " + message->getGameCode() + "\nEspera a que inicie tu juego.";
            ui->label_2->setText(QString::fromStdString(lblStr));
            break;
        }case 2:{
            scrabbleWindow = new ScrabbleWindow(this->parentWidget());
            scrabbleWindow->setConexion(conexion);
            scrabbleWindow->show();
            scrabbleWindow->createPlayerDeck(message->getLetterTiles());
            this->destroy();
            break;
        }case 3:
            out<<"CASE 3\n";
            break;
        default:
            out<<"DEFAULT";
            break;
    }
}
