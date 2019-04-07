#ifndef SCRABBLEWINDOW_H
#define SCRABBLEWINDOW_H

#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLabel>
#include <string>
#include "DraggableTile.h"
#include "clientlogic/Player.hpp"
#include "socketcomunication/socketcliente.h"

using namespace std;

namespace Ui {
class ScrabbleWindow;
}

class ScrabbleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScrabbleWindow(QWidget *parent = 0);
    ~ScrabbleWindow();
    void createBoardFrame(QGraphicsView* view);
    void createPlayerDeck(string letters);
    void resetPlay();
    void placeWordInBoard(string word, vector<vector<int>> wordPositions);
    string getMultiplierFromCSV(int rowPos, int columnPos);
    void setConexion(SocketCliente *conexion);
    SocketCliente* getConexion();
    vector<string> sortPositions(vector<string> wordVector, bool isVertical);

private slots:
    void on_scrabbleButton_clicked();
    void receiveMessage(QString msg);
    void sendMessage();
private:
    Player *player;
    Ui::ScrabbleWindow *ui;
    QGraphicsScene *scene;
    SocketCliente *conexion;
};

#endif // SCRABBLEWINDOW_H
