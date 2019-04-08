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
#include "json/ServerMessage.hpp"
using namespace std;

namespace Ui {
class ScrabbleWindow;
}

//! \brief The ScrabbleWindow class creates a window where the board is graphically located and the actual
//! game flow happens.
class ScrabbleWindow : public QDialog
{
    Q_OBJECT

public:
    //! \brief ScrabbleWindow creates all the widgets to show the full window, calls al the auxiliary methods to
    //! show the user all the graphical components
    explicit ScrabbleWindow(QWidget *parent = 0);
    ~ScrabbleWindow();
    //! \brief createBoardFrame method creates the graphic board, where is displayed every square of the board
    //! with each multiplier.
    void createBoardFrame(QGraphicsView* view);
    //! \brief createPlayerDeck creates the graphic playerDeck with the letters received as parameter.
    //! \param letters: string with letters to add to playerDeck
    void createPlayerDeck(string letters);
    //! \brief resetPlay method clears the words
    void resetPlay();
    //! \brief Receives the word and the positions to add this word to the graphical board
    void placeWordInBoard(string word, vector<vector<int>> wordPositions);
    //! \brief returns the multiplier read in the CSV in the specified row and column
    string getMultiplierFromCSV(int rowPos, int columnPos);
    //! \brief setter for the conexion attribute
    void setConexion(SocketCliente *conexion);
    //! \brief getter for the conexion attribute
    SocketCliente* getConexion();
    //! \brief sorts the positions and word place in a ascendent order.
    vector<string> sortPositions(vector<string> wordVector, bool isVertical);

private slots:
    //! \brief on_scrabbleButton_clicked slot activated when scrabbleButton is clicked. Gets the word
    //! placed in the board and sends it to the server.
    void on_scrabbleButton_clicked();
    //! \brief receiveMessage slot is signaled when the socket receives a message. Parse the msn to a
    //! JSON and manages it depending of the id.
    //! \param msg: Message received via socket.
    void receiveMessage(QString msg);
    //! \brief sendMensaje slot is signaled when acceptCodeButton is clicked. This function
    //! sends the server via socket the codeGame of the game that the user wants to join.
    void sendMessage();
private:
    Player *player;
    Ui::ScrabbleWindow *ui;
    QGraphicsScene *scene;
    SocketCliente *conexion;
};

#endif // SCRABBLEWINDOW_H
