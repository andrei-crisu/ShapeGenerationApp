#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include"inheritedgraphicspolygon.h"
#include"inheritedgraphicsellipse.h"
#include<QTransform>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)override;

signals:
    void sceneMessage(QString str);
};

#endif // CUSTOMSCENE_H
