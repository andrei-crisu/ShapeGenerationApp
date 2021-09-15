#ifndef MYGRAPHICITEM_H
#define MYGRAPHICITEM_H
#include<QtCore>
#include<QGraphicsItem>
#include<QPen>
#include<QPainter>
#include"basic_use.h"

class MyGraphicItem : public QGraphicsItem
{
public:
    MyGraphicItem(double x,double y,double width,double height);
    QRectF boundingRect() const;

    //override paint()
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * option,
               QWidget *widget);

protected:
    //overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    //void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

public:
    bool Pressed;
    bool dblClick;
    bool isHovered;
    double pos_x;
    double pos_y;
    double item_width;
    double item_height;

    QString getToolTip();
};

#endif // MYGRAPHICITEM_H
