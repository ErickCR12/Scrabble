#include "JoinGameWindow.h"
#include "ui_JoinGameWindow.h"
#include "gui/ScrabbleWindow.h"
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>

JoinGameWindow::JoinGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinGameWindow)
{
    ui->setupUi(this);
    conexion = new SocketCliente;
    if(!conexion->connectar())
        QMessageBox::critical(this,"Error","Error al conectar con el servidor",QMessageBox::Ok);

    connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(printMensaje(QString)));
    connect(ui->insertCodeButton,SIGNAL(clicked()),SLOT(sendMensaje()));
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
    QString qCode = ui->codeLineEdit->text();
    string strCode = qCode.toStdString();
    cout << strCode << endl;
    //this->destroy();
    //ScrabbleWindow scrabble;
    //scrabble.setModal(true);
    //scrabble.exec();
}

void JoinGameWindow::sendMensaje()
{
    QString qCode = ui->codeLineEdit->text();
    string strCode = qCode.toStdString();
    conexion->setMensaje(strCode.c_str());
}

void JoinGameWindow::printMensaje(QString msn)
{
    QTextStream out(stdout);
    foreach(QString x, msn){
        out << x;
    }out<<"\n";
}
