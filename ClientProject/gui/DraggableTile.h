#ifndef DRAGGABLETILE_H
#define DRAGGABLETILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class DraggableTile : public QGraphicsRectItem
{
public:
    DraggableTile(QGraphicsItem* parent = 0);
    void setAnchorPoint(const QPointF& anchorPoint);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF anchorPoint;
    bool m_dragged;
};

#endif // DRAGGABLETILE_H
