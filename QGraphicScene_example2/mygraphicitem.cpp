#include "mygraphicitem.h"

MyGraphicItem::MyGraphicItem(double x,double y,double width,double height)
{
    Pressed=false;
    dblClick=false;
    isHovered=false;
    //setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable,true);
    setAcceptHoverEvents(true);
    pos_x=x;
    pos_y=y;
    item_width=width;
    item_height=height;
    setToolTip(getToolTip());

}

QRectF MyGraphicItem::boundingRect() const
{
    return QRectF(pos_x,pos_y,item_width,item_height);
}

void MyGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectangle=boundingRect();

    if(Pressed)
    {
        QPen pen(Qt::darkRed, 1);
        QBrush brush(Qt::darkRed,Qt::Dense4Pattern);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(rectangle);
    }
    else
        if(isHovered)
        {
            QPen pen(Qt::darkYellow, 1);
            QBrush brush(Qt::darkYellow,Qt::Dense4Pattern);
            painter->setPen(pen);
            painter->setBrush(brush);
            painter->drawRect(rectangle);
        }
        else
        {
            QPen pen(Qt::gray,1);
            QBrush brush(Qt::gray,Qt::Dense4Pattern);
            painter->setPen(pen);
            painter->setBrush(brush);
            painter->drawRect(rectangle);
        }
}

QString MyGraphicItem::getToolTip()
{
    QString myToolTip,aux;
    myToolTip=html_sized_text("Shape information",22,true);
    aux="Position: (x=";
    aux+=QString::number(pos_x,'g');
    aux+=",y=";
    aux+=QString::number(pos_y,'g');
    aux+=");";
    myToolTip+=html_sized_text(aux,18);
    return myToolTip;
}

void MyGraphicItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyGraphicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

//void MyGraphicItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
//{
//    dblClick=!dblClick;
//    update();
//    QGraphicsItem::mouseDoubleClickEvent(event);
//}

void MyGraphicItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    isHovered=true;
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void MyGraphicItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    isHovered=false;
    update();
    QGraphicsItem::hoverLeaveEvent(event);

}
