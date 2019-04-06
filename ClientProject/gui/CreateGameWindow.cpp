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
    if(!conexion->connectar())
        QMessageBox::critical(this,"Error","Error al conectar con el servidor",QMessageBox::Ok);

    connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(printMensaje(QString)));
    connect(ui->acceptCreationButton,SIGNAL(clicked()),SLOT(sendMensaje()));
}

CreateGameWindow::~CreateGameWindow()
{
    delete ui;
}

void CreateGameWindow::on_acceptCreationButton_clicked()
{
    cout << "Amount of players: 0" << endl;
}

void CreateGameWindow::on_cancelCreationButton_clicked()
{
    this->destroy();
}

void CreateGameWindow::sendMensaje()
{
    QString qAmount = ui->amountOfPlayersComboBox->currentText();
    ui->amountOfPlayersComboBox->setDisabled(true);
    conexion->setMensaje(qAmount.toStdString().c_str());
}

void CreateGameWindow::printMensaje(QString msn)
{
    QTextStream out(stdout);
    foreach(QString x, msn){
        out << x;
    }out<<"\n";
}
