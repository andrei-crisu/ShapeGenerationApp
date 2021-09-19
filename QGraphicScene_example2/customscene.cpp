#include "customscene.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(QColor(242,242,242)));
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (mouseEvent->button() == Qt::LeftButton)
    {
        QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
        if(!item)
        {
            qDebug()<<"At that location there is nothing";
        }
        else
        {
            InheritedGraphicsPolygon *polygonItem = qgraphicsitem_cast<InheritedGraphicsPolygon *>(item);
            if(polygonItem)
            {
                qDebug() << "It is a polygon item";
            }
            else
            {
                InheritedGraphicsEllipse *ellipseItem = qgraphicsitem_cast<InheritedGraphicsEllipse *>(item);
                if(ellipseItem)
                {
                    qDebug()<<"It is an ellipse";
                }
            }
        }

    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void CustomScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{
    qDebug()<<"Menu event";
    QGraphicsScene::contextMenuEvent(contextMenuEvent);
}
