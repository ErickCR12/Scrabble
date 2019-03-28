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
    this->destroy();
    ScrabbleWindow scrabble;
    scrabble.setModal(true);
    scrabble.exec();
}
