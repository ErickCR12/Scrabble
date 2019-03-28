#include "CreateGameWindow.h"
#include "ui_CreateGameWindow.h"
#include <string>
#include <iostream>
using namespace std;
CreateGameWindow::CreateGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGameWindow)
{
    ui->setupUi(this);
    ui->amountOfPlayersComboBox->addItems({"2", "3", "4"});
}

CreateGameWindow::~CreateGameWindow()
{
    delete ui;
}

void CreateGameWindow::on_acceptCreationButton_clicked()
{
    QString qAmount = ui->amountOfPlayersComboBox->currentText();
    ui->amountOfPlayersComboBox->setDisabled(true);
    int amountOfPlayer = qAmount.toInt();
    cout << "Amount of players: " << amountOfPlayer << endl;
}

void CreateGameWindow::on_cancelCreationButton_clicked()
{
    this->destroy();
}
