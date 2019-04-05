#include "DraggableTile.h"

using namespace std;

DraggableTile::DraggableTile(QGraphicsItem* parent):
    QGraphicsRectItem(parent), m_dragged(false)
{
    setFlags(QGraphicsItem::ItemIsSelectable|
             QGraphicsItem::ItemIsMovable);
}

void DraggableTile::setAnchorPoint(const QPointF &anchorPoint){
    this->anchorPoint = anchorPoint;
}

void DraggableTile::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    m_dragged = true;
    QGraphicsRectItem::mouseMoveEvent(event);
}

void DraggableTile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(m_dragged){
        QList<QGraphicsItem*> colItems = collidingItems();
        if(colItems.isEmpty())
            this->setPos(anchorPoint);               
        else {
            QGraphicsItem* closestItem;
            qreal shortestDist = 100000;
            foreach(QGraphicsItem* item, colItems){
                QLineF line(item->sceneBoundingRect().center(),
                            this->sceneBoundingRect().center());
                if(line.length() < shortestDist){
                    shortestDist = line.length();
                    closestItem = item;
                }
            }
            int column = closestItem->pos().x()/34;
            int row = closestItem->pos().y()/34;
            Board* board = Board::getBoardSingleton();
            if(board->gameBoard[row][column] == ""){
                board->addLetterToBoard(this->getLetter(), row, column);
                this->setPos(closestItem->scenePos());
                setUndraggable();
            }else{
                this->setPos(anchorPoint);
            }
        }m_dragged = false;
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void DraggableTile::setUndraggable(){
    this->setFlags(this->flags()
        .setFlag(QGraphicsItem::ItemIsSelectable, false)
        .setFlag(QGraphicsItem::ItemIsMovable, false));
}

void DraggableTile::setLetter(string letter){
    this->letter = letter;
}

string DraggableTile::getLetter(){
    return letter;
}

void DraggableTile::printGameBoard(Board* board){
    QTextStream out(stdout);
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            out << " ";
            QString string = QString::fromStdString(board->gameBoard[i][j]);
            if(string == "") string = "0";
            foreach(QString x, string){
                out << x;
            }
        }
        out << "\n";
    }
    out << "\n\n\n";
}

