#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <string>
#include <iostream>
using namespace std;

#include "gui/JoinGameWindow.h"
#include "gui/CreateGameWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(QCoreApplication::applicationDirPath() + "/images/mainWindow/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->joinGameButton->setFlat(true);
    ui->createGameButton->setFlat(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_joinGameButton_clicked()
{
    JoinGameWindow joinWindow;
    joinWindow.setModal(true);
    joinWindow.exec();
}

void MainWindow::on_createGameButton_clicked()
{
    CreateGameWindow createWindow;
    createWindow.setModal(true);
    createWindow.exec();
}
