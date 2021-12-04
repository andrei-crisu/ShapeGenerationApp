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
             QString message="At that location there is nothing";
             emit sceneMessage(message);
        }
        else
        {
            InheritedGraphicsPolygon *polygonItem = qgraphicsitem_cast<InheritedGraphicsPolygon *>(item);
            if(polygonItem)
            {
                 QString message="It is a polygon item";
                 emit sceneMessage(message);
            }
            else
            {
                InheritedGraphicsEllipse *ellipseItem = qgraphicsitem_cast<InheritedGraphicsEllipse *>(item);
                if(ellipseItem)
                {
                    QString message="It is an ellipse";
                    emit sceneMessage(message);
                }
            }
        }

    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void CustomScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{
     QString message="Menu event";
     emit sceneMessage(message);
    QGraphicsScene::contextMenuEvent(contextMenuEvent);
}
