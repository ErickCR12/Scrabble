#include "mainwindow.h"
#include <string>
#include <iostream>
#include <vector>
#include <QApplication>
#include "PlayerTest.hpp"
using namespace std;

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    PlayerTest::test1();

    return 0;
//    return a.exec();
}
