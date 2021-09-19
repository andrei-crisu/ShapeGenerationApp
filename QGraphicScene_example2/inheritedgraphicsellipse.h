#ifndef INHERITEDGRAPHICSELLIPSE_H
#define INHERITEDGRAPHICSELLIPSE_H

#include <QGraphicsEllipseItem>
#include<QtCore>
#include<QGraphicsItem>
#include<QPen>
#include<QPainter>
#include"basic_use.h"
#include<QGraphicsScene>
#include<QGraphicsSceneMouseEvent>

class InheritedGraphicsEllipse : public QGraphicsEllipseItem
{
public:
    InheritedGraphicsEllipse(QRectF &rect);
    //override paint()
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * option,
               QWidget *widget)override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    protected:
        //overriding mouse events
        void mousePressEvent(QGraphicsSceneMouseEvent *event )override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event)override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event)override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event)override;
public:
    bool Pressed;
    bool dblClick;
    bool isHovered;
    double pos_x;
    double pos_y;
    double bounding_rectangle_width;
    double bounding_rectangle_height;
    QRectF bounding_rect;

    QString getToolTip();
};

#endif // INHERITEDGRAPHICSELLIPSE_H
