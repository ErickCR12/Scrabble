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

private:
    Ui::ScrabbleWindow *ui;
    void createBoardFrame(QGraphicsScene* scene, QGraphicsView* view);
    void createPlayerDeckFrame(QGraphicsScene* scene, QGraphicsView* view);
};

#endif // SCRABBLEWINDOW_H
