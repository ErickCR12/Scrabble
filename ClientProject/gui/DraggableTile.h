#ifndef DRAGGABLETILE_H
#define DRAGGABLETILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QTextStream>
#include <string>

#include "clientlogic/Board.hpp"

class DraggableTile : public QGraphicsRectItem
{
public:
    DraggableTile(QGraphicsItem* parent = 0);
    void setAnchorPoint(const QPointF& anchorPoint);
    void printGameBoard(Board* board);
    void setUndraggable();
    std::string getLetter();
    void setLetter(string letter);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF anchorPoint;
    bool m_dragged;
    std::string letter;
};

#endif // DRAGGABLETILE_H
