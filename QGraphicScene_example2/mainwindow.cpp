#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"basic_use.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new CustomScene(this);
    ui->graphicsView->setScene(scene);


    //
    QPolygonF polygon,polygon2;
    polygon.append(QPointF(20,50));
    polygon.append(QPointF(100,60));
    polygon.append(QPointF(120,100));
    polygon.append(QPointF(100,140));
    polygon.append(QPointF(40,140));
    polygon.append(QPointF(30,80));
    polygon.append(QPointF(0,80));

    polygon2.append(QPointF(-100,-100));
    polygon2.append(QPointF(-50,-100));
    polygon2.append(QPointF(-50,-20));
    polygon2.append(QPointF(-100,-20));


    scene->addItem(new InheritedGraphicsPolygon(polygon));
    scene->addRect(0,0,100,20);
    scene->addItem(new InheritedGraphicsPolygon(polygon2));

}

MainWindow::~MainWindow()
{
    delete ui;
}


