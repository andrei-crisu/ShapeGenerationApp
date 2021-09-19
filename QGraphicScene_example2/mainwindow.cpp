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
    QPolygonF polygon;
    polygon.append(QPointF(20,50));
    polygon.append(QPointF(100,60));
    polygon.append(QPointF(120,100));
    polygon.append(QPointF(100,140));
    polygon.append(QPointF(40,140));
    polygon.append(QPointF(30,80));
    polygon.append(QPointF(0,80));

    QPolygonF polygon2;
    polygon2.append(QPointF(-100,-100));
    polygon2.append(QPointF(-50,-100));
    polygon2.append(QPointF(-50,-20));
    polygon2.append(QPointF(-100,-20));

    QPolygonF polygon3;
    polygon3.append(QPointF(-600,-500));
    polygon3.append(QPointF(-300,-400));
    polygon3.append(QPointF(-800,-300));
    polygon3.append(QPointF(-750,-380));

    scene->addItem(new InheritedGraphicsPolygon(polygon));
    QRectF rect(-100,-100,300,400);
    QRectF rect1(QRectF(-300,-100,400,320));
    QRectF rect2(QRectF(-300,-500,400,320));
    scene->addRect(rect);
    scene->addItem(new InheritedGraphicsEllipse(rect1));
    scene->addItem(new InheritedGraphicsEllipse(rect2));
    scene->addItem(new InheritedGraphicsPolygon(polygon2));
    scene->addItem(new InheritedGraphicsPolygon(polygon3));
    QTimer timer(this);
    timer.singleShot(10,this,&MainWindow::onTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"Window resized";
    QMainWindow::resizeEvent(event);
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug()<<"Windows closed";
    QMainWindow::closeEvent(event);
}

void MainWindow::onTimer()
{
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}


void MainWindow::on_splitter_splitterMoved(int , int )
{
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}


void MainWindow::on_polygonButton_clicked()
{
    ui->ellipseButton->setEnabled(true);
    ui->polygonButton->setEnabled(false);
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_ellipseButton_clicked()
{
    ui->ellipseButton->setEnabled(false);
    ui->polygonButton->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(0);
}

