#include "ScrabbleWindow.h"
#include "ui_ScrabbleWindow.h"
#include <iostream>

ScrabbleWindow::ScrabbleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScrabbleWindow)
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,775,675);
    QGraphicsView* view = new QGraphicsView(scene);
    QVBoxLayout* verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(view);

    createBoardFrame(scene, view);
    createPlayerDeckFrame(scene, view);
}

void ScrabbleWindow::createBoardFrame(QGraphicsScene* scene, QGraphicsView* view){

    int rectangleSize = 34;
    QRectF rect(0,0,rectangleSize,rectangleSize);
    QBrush myBrush(Qt::darkGray, Qt::Dense5Pattern);
    int initialPosition = 0;
    int xPos = initialPosition;
    int yPos = initialPosition;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            QGraphicsRectItem *rItem1 = new QGraphicsRectItem(rect);
            scene->addItem(rItem1);
            rItem1->setPos(xPos,yPos);
            rItem1->setBrush(myBrush);
            xPos += rectangleSize;
        }
        xPos = initialPosition;
        yPos += rectangleSize;
    }
}


void ScrabbleWindow::createPlayerDeckFrame(QGraphicsScene* scene, QGraphicsView* view){

    int rectangleSize = 34;
    QRectF rect(0,0,rectangleSize,rectangleSize);
    QBrush myBrush(Qt::darkGray, Qt::Dense5Pattern);

    DraggableTile *dItem;
    int yPos = 150;
    for(int j = 0; j < 7; j++){
        dItem = new DraggableTile;
        scene->addItem(dItem);
        dItem->setRect(rect);
        dItem->setPos(530,yPos);
        dItem->setBrush(QBrush(QColor("#ffa07a")));
        dItem->setAnchorPoint(dItem->pos());
        yPos += 38;
    }

}


//    QGraphicsScene *scene = new QGraphicsScene(this);
//    scene->setSceneRect(0,0,280,240);
//    QGraphicsView *view = new QGraphicsView(scene);
//    setCentralWidget(view);

//    QRectF rect(0,0,80,40);
//    QBrush myBrush(Qt::darkGray, Qt::Dense5Pattern);

//    QGraphicsRectItem *rItem1 = new QGraphicsRectItem(rect);
//    scene->addItem(rItem1);
//    rItem1->setPos(160,40);
//    rItem1->setBrush(myBrush);

//    QGraphicsRectItem *rItem2 = new QGraphicsRectItem(rect);
//    scene->addItem(rItem2);
//    rItem2->setPos(160,100);
//    rItem2->setBrush(myBrush);

//    QGraphicsRectItem *rItem3 = new QGraphicsRectItem(rect);
//    scene->addItem(rItem3);
//    rItem3->setPos(160,160);
//    rItem3->setBrush(myBrush);

//    DraggableTile *dItem = new DraggableTile;
//    scene->addItem(dItem);
//    dItem->setRect(rect);
//    dItem->setPos(30,100);
//    dItem->setBrush(QBrush(QColor("#ffa07a")));
//    dItem->setAnchorPoint(dItem->pos());
//}

ScrabbleWindow::~ScrabbleWindow()
{
    delete ui;
}
