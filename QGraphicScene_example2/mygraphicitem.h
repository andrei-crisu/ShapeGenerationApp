#ifndef MYGRAPHICITEM_H
#define MYGRAPHICITEM_H
#include<QtCore>
#include<QGraphicsItem>
#include<QPen>
#include<QPainter>
#include"basic_use.h"

class MyGraphicItem : public QGraphicsPolygonItem
{
public:
    MyGraphicItem(QPolygonF &init_polygon);

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
    //void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)override;
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
    QPolygonF polygon;

    QString getToolTip();
};

#endif // MYGRAPHICITEM_H
