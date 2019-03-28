#include <string>
#include <iostream>
#include <vector>
#include <QApplication>
#include "gui/MainWindow.h"
#include "gui/ScrabbleWindow.h"
#include "tests/PlayerTest.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //PlayerTest::test2();

    return a.exec();
}
