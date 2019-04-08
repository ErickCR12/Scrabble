#ifndef DRAGGABLETILE_H
#define DRAGGABLETILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QTextStream>
#include <string>

#include "clientlogic/Board.hpp"

//! \brief The DraggableTile class is a QGraphicsRectItem that can be dragged around a QGraphicsView. Is used as the scrabble tiles.
class DraggableTile : public QGraphicsRectItem
{
public:
    //! \brief DraggableTile constructor. Set flags of selectable and draggable to true.
    //! \param paren: widget parent of draggableTile.
    DraggableTile(QGraphicsItem* parent = 0);
    //! \brief setAnchorPoint function sets the position of the draggableTile to the QPointF received as parameter.
    //! \param anchorPoint: QPointF
    void setAnchorPoint(const QPointF& anchorPoint);
    void printGameBoard(Board* board);
    //! \brief setUndraggable function sets flags of selectable and draggable to false.
    void setUndraggable();
    //! \brief getter for letter attribute
    //! \return string: letter attribute
    std::string getLetter();
    //! \brief settter for letter attribute
    //! \param string: new letter value
    void setLetter(string letter);
protected:
    //! \brief event that makes the tile draggable
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    //! \brief this event registers when the draggable tile is released. Checks if theres an QRectF item close
    //! and set as a new anchor point the position of this QRectF
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF anchorPoint;
    bool m_dragged;
    std::string letter;
};

#endif // DRAGGABLETILE_H
