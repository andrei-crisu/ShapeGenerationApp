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
            qDebug() << "is an item" << mouseEvent->scenePos();
        }
        else
            qDebug() << "NOT an item" << mouseEvent->scenePos();
    }

}
