#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"basic_use.h"
#include<QtAlgorithms>
#include<QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new CustomScene(this);
    ui->graphicsView->setScene(scene);
    connect(scene,&CustomScene::sceneMessage,this,&MainWindow::showMessage);

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


void MainWindow::on_polygonButtonShape_clicked()
{
    ui->ellipseButtonShape->setEnabled(true);
    ui->polygonButtonShape->setEnabled(false);
    ui->stackedWidget_2->setCurrentIndex(2);
}


void MainWindow::on_ellipseButtonShape_clicked()
{
    ui->ellipseButtonShape->setEnabled(false);
    ui->polygonButtonShape->setEnabled(true);
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
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

}


void MainWindow::on_clearButton_clicked()
{
    scene->clear();
    ui->graphicsView->fitInView(QRectF(0,0,100,200),Qt::KeepAspectRatio);
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
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("Polygon added!",4000);
}


void MainWindow::on_addRandomPolygon_clicked()
{
    //this code will generate a random regular polygon:
    //[at a random position,with a random number of vertices]
    //where x is in [-300,300]
    //and y is in [-300,300]


    //generate the number of vertices
    int nr=QRandomGenerator::global()->bounded(3,18);
    float angleStep;
    angleStep=360/(float)nr;

    float x,y,r,xOrigin,yOrigin,angleValue;
    //generate radius of circumscribed circle
    r=QRandomGenerator::global()->bounded(60,121);

    //generate random center coordinates
    QPolygonF polygon;
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);
    for(int i=0;i<nr;i++)
    {
        angleValue=i*angleStep;
        x=r*qCos(qDegreesToRadians(angleValue));
        y=r*qSin(qDegreesToRadians(angleValue));
        polygon.append(QPointF(xOrigin+x,yOrigin+y));
    }
    scene->addItem(new InheritedGraphicsPolygon(polygon));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("RANDOM:: Regular polygon generated!",4000);

}


void MainWindow::on_addRandomIrregularPolygon_clicked()
{
    //this code will generate a random irregular polygon:
    //[at a random position,with a random number of vertices]
    //where x is in [-300,300]
    //and y is in [-300,300]


    //generate the number of vertices
    //this may not be the final number of vertices
    //duplicates angles will be deleted
    //this will result in a smaller number of vertices in comparison
    //with [nr] which was initially generated
    int nr=QRandomGenerator::global()->bounded(8,24);
    int val;
    bool duplicateFlag=false;
    QList<int> firstList;
    for(int i=1;i<=nr;i++)
    {
        val=QRandomGenerator::global()->bounded(0,360);
        for(int i=0;i<firstList.length();i++)
            if(val==firstList.at(i))
            {
                duplicateFlag=true;
                break;
            }
            else
            {
                duplicateFlag=false;
            }
        if(!duplicateFlag)
            firstList.append(val);
    }
    int aux;
    //sorting list
    for(int i=0;i<firstList.length()-1;i++)
        for(int j=i+1;j<firstList.length();j++)
            if(firstList.at(i)<firstList.at(j))
            {
                aux=firstList.at(i);
                firstList.replace(i,firstList.at(j));
                firstList.replace(j,aux);

            }
    nr=firstList.length();
    QPolygonF polygon;
    float x,y,r,xOrigin,yOrigin;
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);
    for(int i=0;i<nr;i++)
    {
        r=QRandomGenerator::global()->bounded(20,101);
        val=firstList.at(i);
        x=r*qCos(qDegreesToRadians(val));
        y=r*qSin(qDegreesToRadians(val));
        polygon.append(QPointF(xOrigin+x,yOrigin+y));
    }
    scene->addItem(new InheritedGraphicsPolygon(polygon));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("RANDOM:: Irregular polygon generated!",4000);

}



void MainWindow::on_shapeDrawing_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_addRandomPolygon_2_clicked()
{
    //do nothing()
    //just added to prevent a bug with moc file
}


void MainWindow::on_close_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

