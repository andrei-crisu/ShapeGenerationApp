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

    // create our object and add it to the scene
    for(int i=10;i<=400;i+=210)
        for(int j=10;j<=200;j+=60)
        {
            scene->addItem(new MyGraphicItem(i,j,200,50));
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}


