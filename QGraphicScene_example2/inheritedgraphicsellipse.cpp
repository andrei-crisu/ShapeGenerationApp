#include "inheritedgraphicsellipse.h"

InheritedGraphicsEllipse::InheritedGraphicsEllipse(QRectF &rect):QGraphicsEllipseItem(rect)
{
    Pressed=false;
    dblClick=false;
    isHovered=false;
    //setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable,true);
    setAcceptHoverEvents(true);
    pos_x=rect.x();
    pos_y=rect.y();
    bounding_rectangle_width=rect.width();
    bounding_rectangle_height=rect.height();
    setToolTip(getToolTip());
    bounding_rect=rect;
}

void InheritedGraphicsEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPainterPath path;

    if(Pressed)
    {
        QPen pen(Qt::darkGreen, 1);
        QBrush brush(Qt::green,Qt::SolidPattern);
        painter->setPen(pen);
        painter->setBrush(brush);
        // Draw polygon with background
        path.addEllipse(bounding_rect);
        painter->drawEllipse(bounding_rect);
        painter->fillPath(path, brush);
    }
    else
        if(isHovered)
        {
            QPen pen(Qt::darkYellow, 1);
            QBrush brush(Qt::yellow,Qt::SolidPattern);
            painter->setPen(pen);
            painter->setBrush(brush);
            // Draw polygon with background
            path.addEllipse(bounding_rect);
            painter->drawEllipse(bounding_rect);
            painter->fillPath(path, brush);

        }
        else
        {   /*if(!scene()->collidingItems(this).isEmpty())
            {
                QPen pen(Qt::darkRed,1);
                QBrush brush(Qt::darkRed,Qt::SolidPattern);
                painter->setPen(pen);
                painter->setBrush(brush);
                // Draw polygon with background
                path.addEllipse(bounding_rect);
                painter->drawEllipse(bounding_rect);
                painter->fillPath(path, brush);

            }
            else*/
            {
            QPen pen(Qt::darkGray,1);
            QBrush brush(Qt::gray,Qt::SolidPattern);
            painter->setPen(pen);
            painter->setBrush(brush);
            // Draw polygon with background
            path.addEllipse(bounding_rect);
            painter->drawEllipse(bounding_rect);
            painter->fillPath(path, brush);
            }

        }
}

QRectF InheritedGraphicsEllipse::boundingRect() const
{
    return QGraphicsEllipseItem::boundingRect();
}

QPainterPath InheritedGraphicsEllipse::shape() const
{
    return QGraphicsEllipseItem::shape();
}

QString InheritedGraphicsEllipse::getToolTip()
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
    aux+="Ellipse";
    aux+="<br>";
    myToolTip+=html_sized_text(aux,18);
    return myToolTip;
}

void InheritedGraphicsEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        Pressed = true;
        update();
        QGraphicsEllipseItem::mousePressEvent(event);
    }
}

void InheritedGraphicsEllipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsEllipseItem::mouseReleaseEvent(event);
}

void InheritedGraphicsEllipse::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    isHovered=true;
    update();
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void InheritedGraphicsEllipse::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    isHovered=false;
    update();
    QGraphicsEllipseItem::hoverLeaveEvent(event);

}
