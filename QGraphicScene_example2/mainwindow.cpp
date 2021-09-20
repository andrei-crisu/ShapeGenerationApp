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
    connect(scene,&CustomScene::sceneMessage,this,&MainWindow::showMessage);


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

    scene->addItem(new InheritedGraphicsPolygon(polygon));
    scene->addItem(new InheritedGraphicsPolygon(polygon2));
    QTimer timer(this);
    timer.singleShot(10,this,&MainWindow::onTimer);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}

void MainWindow::onTimer()
{
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::showMessage(const QString string)
{
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage(string,4000);
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


void MainWindow::on_clearEllipseData_clicked()
{
    ui->x_pos_lineEdit->clear();
    ui->y_pos_lineEdit->clear();
    ui->width_lineEdit->clear();
    ui->height_lineEdit->clear();
}


void MainWindow::on_addEllipse_clicked()
{
    QString w_string,h_string,x_string,y_string;
    //get data as string from ui
    w_string=ui->width_lineEdit->text();
    h_string=ui->height_lineEdit->text();
    x_string=ui->x_pos_lineEdit->text();
    y_string=ui->y_pos_lineEdit->text();

    bool ok=false;
    double width,height,x_pos,y_pos;
    if(w_string.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Width not specified!",4000);
        return;
    }
    if(h_string.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Height not specified",4000);
        return;
    }

    if(x_string.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("X position not specified!",4000);
        return;
    }
    if(y_string.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Y position not specified",4000);
        return;
    }

    ok=false;
    width=w_string.toDouble(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Width field: [ "+w_string+" ] contain mistakes; not a number!",4000);
        return;
    }

    ok=false;
    height=h_string.toDouble(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Height field: [ "+h_string+" ] contain mistakes; not a number !",4000);
        return;
    }

    ok=false;
    x_pos=x_string.toDouble(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("X field: [ "+x_string+" ] contain mistakes; not a number !",4000);
        return;
    }

    ok=false;
    y_pos=y_string.toDouble(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Y field: [ "+y_string+" ] contain mistakes; not a number !",4000);
        return;
    }

    if(width<0||height<0)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Width or height can't be negative"
                                   ": [ ("+w_string+","+h_string+") ]",4000);
        return;
    }

    ui->statusbar->setStyleSheet("color: #112090;"
                                  "font: 14pt; ");
    ui->statusbar->showMessage("Added an ellipse with bounding rectangle:[ "+QString::number(x_pos)+", "
                               +QString::number(y_pos)+", "+QString::number(width)+", "
                               +QString::number(height)+" ];",10000);

    QRectF rect(x_pos,y_pos,width,height);
    scene->addItem(new InheritedGraphicsEllipse(rect));

}


void MainWindow::on_clearButton_clicked()
{
   scene->clear();
}


void MainWindow::on_zoomInButtton_clicked()
{
    ui->graphicsView->scale(1.1,1.1);
}


void MainWindow::on_zoomOutButton_clicked()
{
    ui->graphicsView->scale(0.9,0.9);
}


void MainWindow::on_zoomToFitButton_clicked()
{
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}


void MainWindow::on_clearPolygonData_clicked()
{

}


void MainWindow::on_addPolygon_clicked()
{
    QString data_string=ui->polygonVerticesEdit->toPlainText();
    QString x_string,y_string;
    double x,y;
    QPolygonF polygon;
    bool ok=false;
    QRegularExpression space("\\s");
    QRegularExpression semicolon("\\;");
    QRegularExpression comma("\\,");
    data_string.remove(space);
    if(data_string.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                      "font: 14pt; ");
        ui->statusbar->showMessage("Empty field: no data provided!",4000);
        return;
    }
    if(data_string.length()<4)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                      "font: 14pt; ");
        ui->statusbar->showMessage("Data string loaded from file : too short [ wrong syntax ]",4000);
        return;
    }
    if(data_string.at(data_string.length()-1)==';')
        data_string=data_string.left(data_string.length()-1);

    QStringList verticiesList=data_string.split(semicolon);
    for(int i=0;i<verticiesList.length();i++)
    {
        QStringList vertexToken=verticiesList.at(i).split(comma);
        if(vertexToken.length()!=2)
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                          "font: 14pt; ");
            ui->statusbar->showMessage("Error: data provided contain mistakes!",4000);
            return;
        }
        else
        {
            x_string=vertexToken.at(0);
            y_string=vertexToken.at(1);
            if(x_string.isEmpty()||y_string.isEmpty())
            {
                ui->statusbar->setStyleSheet("color: #AA0000;"
                                              "font: 14pt; ");
                ui->statusbar->showMessage("Error at: "+verticiesList.at(i),4000);
                return;
            }
            ok=false;
            x=x_string.toDouble(&ok);
            if(!ok)
            {
                ui->statusbar->setStyleSheet("color: #AA0000;"
                                              "font: 14pt; ");
                ui->statusbar->showMessage("Error: [ "+x_string+" ] contain mistakes;not a number !",4000);
                return;
            }

            ok=false;
            y=y_string.toDouble(&ok);
            if(!ok)
            {
                ui->statusbar->setStyleSheet("color: #AA0000;"
                                              "font: 14pt; ");
                ui->statusbar->showMessage("Error: [ "+y_string+" ] contain mistakes;not a number !",4000);
                return;
            }
            polygon.append(QPointF(x,y));
        }
    }

    scene->addItem(new InheritedGraphicsPolygon(polygon));
    ui->statusbar->setStyleSheet("color: #112090;"
                                  "font: 14pt; ");
    ui->statusbar->showMessage("Polygon added!",4000);
}

