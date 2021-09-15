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
    for(int i=10;i<=400;i+=110)
        for(int j=10;j<=200;j+=40)
        {
            scene->addItem(new MyGraphicItem(i,j,100,30));
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}


