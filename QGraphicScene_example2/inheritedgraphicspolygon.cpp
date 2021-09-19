#include "inheritedgraphicspolygon.h"
#include<QGraphicsSceneMouseEvent>

InheritedGraphicsPolygon::InheritedGraphicsPolygon(QPolygonF &other_polygon):QGraphicsPolygonItem(other_polygon)
{
    Pressed=false;
    dblClick=false;
    isHovered=false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemSendsGeometryChanges,true);
    setAcceptHoverEvents(true);
    QRectF rect=other_polygon.boundingRect();
    pos_x=rect.x();
    pos_y=rect.y();
    bounding_rectangle_width=rect.width();
    bounding_rectangle_height=rect.height();
    setToolTip(getToolTip());
    setPolygon(other_polygon);
}

void InheritedGraphicsPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPainterPath path;
    if(Pressed)
    {
        QPen pen(Qt::darkGreen, 1);
        QBrush brush(Qt::darkGreen,Qt::Dense4Pattern);
        painter->setPen(pen);
        painter->setBrush(brush);
        // Draw polygon with background
        path.addPolygon(polygon());
        painter->drawPolygon(polygon());
        painter->fillPath(path, brush);
    }
    else
        if(isHovered)
        {
            QPen pen(Qt::darkYellow, 1);
            QBrush brush(Qt::darkYellow,Qt::Dense4Pattern);
            painter->setPen(pen);
            painter->setBrush(brush);
            // Draw polygon with background
            path.addPolygon(polygon());
            painter->drawPolygon(polygon());
            painter->fillPath(path, brush);

        }
        else
        {
            if(!scene()->collidingItems(this).isEmpty())
            {
                QPen pen(Qt::darkRed,1);
                QBrush brush(Qt::darkRed,Qt::Dense4Pattern);
                painter->setPen(pen);
                painter->setBrush(brush);
                // Draw polygon with background
                path.addPolygon(polygon());
                painter->drawPolygon(polygon());
                painter->fillPath(path, brush);
            }
            else
            {
                QPen pen(Qt::darkGray,1);
                QBrush brush(Qt::darkGray,Qt::Dense4Pattern);
                painter->setPen(pen);
                painter->setBrush(brush);
                // Draw polygon with background
                path.addPolygon(polygon());
                painter->drawPolygon(polygon());
                painter->fillPath(path, brush);
            }

        }
    // QGraphicsPolygonItem::paint(painter,option,widget);
}

QRectF InheritedGraphicsPolygon::boundingRect() const
{
    return QGraphicsPolygonItem::boundingRect();
}

QPainterPath InheritedGraphicsPolygon::shape() const
{
    return QGraphicsPolygonItem::shape();
}

QString InheritedGraphicsPolygon::getToolTip()
{
    QString myToolTip,aux;
    myToolTip=html_sized_text("Shape information",22,true);
    aux="Bounding rectangle:";
    aux+="<br>";
    aux+="Position: (x=";
    aux+=QString::number(pos_x,'g');
    aux+=",y=";
    aux+=QString::number(pos_y,'g');
    aux+=");";
    aux+="<br>";
    aux+="Type: ";
    aux+="Polygon";
    aux+="<br>";
    myToolTip+=html_sized_text(aux,18);
    return myToolTip;
}

void InheritedGraphicsPolygon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        Pressed = true;
        update();
        QGraphicsPolygonItem::mousePressEvent(event);
    }
}

void InheritedGraphicsPolygon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsPolygonItem::mouseReleaseEvent(event);
}

void InheritedGraphicsPolygon::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    isHovered=true;
    update();
    QGraphicsPolygonItem::hoverEnterEvent(event);
}

void InheritedGraphicsPolygon::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    isHovered=false;
    update();
    QGraphicsPolygonItem::hoverLeaveEvent(event);

}

void InheritedGraphicsPolygon::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
//    dblClick=!dblClick;
//   setFlag(ItemIsMovable,dblClick);
//    update();
    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
}

