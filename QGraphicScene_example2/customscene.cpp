#include "customscene.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent)
{

}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (mouseEvent->button() == Qt::LeftButton)
    {
        QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere
        MyGraphicItem *myItem = qgraphicsitem_cast<MyGraphicItem *>(item);
        if(myItem)
        {
            qDebug() << "is a polygon item" << mouseEvent->scenePos();
        }
        else
            if(item)
            {
                qDebug() << "NOT a polygon item...but other shape" << mouseEvent->scenePos();
            }
        else
            {
                qDebug()<<"Nothing";
            }

    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}
