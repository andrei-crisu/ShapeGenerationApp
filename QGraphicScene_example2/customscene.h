#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include"inheritedgraphicspolygon.h"
#include<QTransform>

class CustomScene : public QGraphicsScene
{
public:
    explicit CustomScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // CUSTOMSCENE_H
