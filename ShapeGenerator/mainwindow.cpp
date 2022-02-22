#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"basic_use.h"
#include<QtAlgorithms>
#include<QtMath>
#include<QAction>

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

//this function draws a custom triangle( vertices are given)
void MainWindow::drawCustomTriangle()
{
    QString strAx,strAy,strBx,strBy,strCx,strCy;
    float xA,yA,xB,yB,xC,yC;
    bool ok;
    //get data from ui    
    strAx=ui->inputvAx->text();
    strAy=ui->inputvAy->text();
    strBx=ui->inputvBx->text();
    strBy=ui->inputvBy->text();
    strCx=ui->inputvCx->text();
    strCy=ui->inputvCy->text();
    //check if the user introduced data in the corresponding fields
    if(strAx.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("x coordinate for Vertex1 is not specified!",4000);
        return;
    }
    if(strAy.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("y coordinate for Vertex1 is not specified!",4000);
        return;
    }
    if(strBx.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("x coordinate for Vertex2 is not specified!",4000);
        return;
    }
    if(strBy.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("y coordinate for Vertex2 is not specified!",4000);
        return;
    }
    if(strCx.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("x coordinate for Vertex3 is not specified!",4000);
        return;
    }
    if(strCy.isEmpty())
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("y coordinate for Vertex3 is not specified!",4000);
        return;
    }
    //data is extracted as string
    //now data must be checked to see if there are errors
    //if not strings will be converted to float values
    //extract Vertex1 coordinates
    ok=false;
    xA=strAx.toFloat(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Vertex1 x field: [ "+strAx+" ] contain mistakes; not a number!",4000);
        return;
    }
    ok=false;
    yA=strAy.toFloat(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Vertex1 y field: [ "+strAy+" ] contain mistakes; not a number!",4000);
        return;
    }

    //extract Vertex2 coordinates
    ok=false;
    xB=strBx.toFloat(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Vertex2 x field: [ "+strBx+" ] contain mistakes; not a number!",4000);
        return;
    }
    ok=false;
    yB=strBy.toFloat(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Vertex2 y field: [ "+strBy+" ] contain mistakes; not a number!",4000);
        return;
    }

    //extract Vertex3 coordinates
    ok=false;
    xC=strCx.toFloat(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Vertex3 x field: [ "+strCx+" ] contain mistakes; not a number!",4000);
        return;
    }
    ok=false;
    yC=strCy.toFloat(&ok);
    if(!ok)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Vertex3 y field: [ "+strCy+" ] contain mistakes; not a number!",4000);
        return;
    }
    //test if A,B,C are not colinear
    //cretate triangle with vertices A,B,C
    //basically the are of triangle is computed
    //if the area is 0 it means that the three points are on the same line ( are colinear)
    float triangleArea;
    triangleArea=(xA*(yB-yC)+xB*(yC-yA)+xC*(yA-yB))/2.0;
    if(triangleArea==0)
    {
        ui->statusbar->setStyleSheet("color: #AA0000;"
                                     "font: 14pt; ");
        ui->statusbar->showMessage("Given points are colinear.A triangle can't be cretated with these points!",4000);
        return;
    }
    QPolygonF custom_triangle;
    custom_triangle.append(QPointF(xA,yA));
    custom_triangle.append(QPointF(xB,yB));
    custom_triangle.append(QPointF(xC,yC));
    //add it to the scene
    scene->addItem(new InheritedGraphicsPolygon(custom_triangle));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("Custom triangle added!",10000);
}

//this function draws an equilateral triangle
void MainWindow::drawEquilateralTriangle()
{
    //number of vertices is 3
    int nr=3;
    float angleStep;
    angleStep=360/(float)nr;

    float x,y,r,xOrigin,yOrigin,angleValue;
    //generate radius of circumscribed circle
    r=QRandomGenerator::global()->bounded(30,240);

    //generate random center coordinates
    QPolygonF equilateral_triangle;
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);
    for(int i=0;i<nr;i++)
    {
        angleValue=i*angleStep;
        x=r*qCos(qDegreesToRadians(angleValue));
        y=r*qSin(qDegreesToRadians(angleValue));
        equilateral_triangle.append(QPointF(xOrigin+x,yOrigin+y));
    }
    scene->addItem(new InheritedGraphicsPolygon(equilateral_triangle));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("RANDOM:: Equilateral triangle generated!",4000);
}

//this function draws an isosceles triangle
void MainWindow::drawIsocscelesTriangle()
{
    float xP,yP,height,half_of_base,teta;
    float xA,yA,xB,yB,xC,yC;//will contain values relative to point P(xP,yP)
    float x,y;
    //it generates height of the isosceles triangle
    height=QRandomGenerator::global()->bounded(120,240);
    //it generates a number that represent half of the triangle base
    //It is considered base the side that has the equal angles next to it
    half_of_base=QRandomGenerator::global()->bounded(30,120);

    QPolygonF isosceles_triangle;
    //The coordinates of the point P are generated
    //P(xp,yp) represent the point located in the middle of the side
    xP=QRandomGenerator::global()->bounded(-300,301);
    yP=QRandomGenerator::global()->bounded(-300,301);
    //cartesian coordinates of vertices A,B,C relative to point P
    xA=xP;
    yA=yP+height;
    xB=xP-half_of_base;
    yB=yP;
    xC=xP+half_of_base;
    yC=yP;

    //initially is considered that  the triangle has the base parallel to the Ox axis;
    //the isosceles triangle is rotated with a random angle between 0 and 360 degrees
    teta=QRandomGenerator::global()->bounded(0,360);
    //vertex A coordinates after rotation
    x=xA;
    y=yA;
    xA=(x-xP)*qCos(qDegreesToRadians(teta))-(y-yP)*qSin(qDegreesToRadians(teta))+xP;
    yA=(x-xP)*qSin(qDegreesToRadians(teta))+(y-yP)*qCos(qDegreesToRadians(teta))+yP;
    //vertex B coordinates after rotation
    x=xB;
    y=yB;
    xB=(x-xP)*qCos(qDegreesToRadians(teta))-(y-yP)*qSin(qDegreesToRadians(teta))+xP;
    yB=(x-xP)*qSin(qDegreesToRadians(teta))+(y-yP)*qCos(qDegreesToRadians(teta))+yP;
    //vertex C coordinates after rotation
    x=xC;
    y=yC;
    xC=(x-xP)*qCos(qDegreesToRadians(teta))-(y-yP)*qSin(qDegreesToRadians(teta))+xP;
    yC=(x-xP)*qSin(qDegreesToRadians(teta))+(y-yP)*qCos(qDegreesToRadians(teta))+yP;

    isosceles_triangle.append(QPointF(xA,yA));
    isosceles_triangle.append(QPointF(xB,yB));
    isosceles_triangle.append(QPointF(xC,yC));


    scene->addItem(new InheritedGraphicsPolygon(isosceles_triangle));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("RANDOM:: Isosceles triangle generated!",4000);
}

//this function draws a scalene triangle
//(this means that the triangle sides have different lengths)
void MainWindow::drawScaleneTriangle()
{
    float r,xOrigin,yOrigin;
    float tetaA,tetaB,tetaC;
    float xA,yA,xB,yB,xC,yC;

    //generate radius of circumscribed circle
    r=QRandomGenerator::global()->bounded(120,320);
    //generate polar coordintate (teta) for each point
    tetaA=QRandomGenerator::global()->bounded(0,180);
    tetaB=QRandomGenerator::global()->bounded(180,270);
    tetaC=QRandomGenerator::global()->bounded(270,360);

    QPolygonF scaleneTriangle;
    //origin of circumscribed circle
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);

    //cartesian coordinates of vertex A relative to Origin(xOrigin,yOrigin)
    xA=r*qCos(qDegreesToRadians(tetaA));
    yA=r*qSin(qDegreesToRadians(tetaA));
    //cartesian coordinates of vertex B relative to Origin(xOrigin,yOrigin)
    xB=r*qCos(qDegreesToRadians(tetaB));
    yB=r*qSin(qDegreesToRadians(tetaB));
    //cartesian coordinates of vertex C relative to Origin(xOrigin,yOrigin)
    xC=r*qCos(qDegreesToRadians(tetaC));
    yC=r*qSin(qDegreesToRadians(tetaC));

    scaleneTriangle.append(QPointF(xOrigin+xA,yOrigin+yA));
    scaleneTriangle.append(QPointF(xOrigin+xB,yOrigin+yB));
    scaleneTriangle.append(QPointF(xOrigin+xC,yOrigin+yC));

    scene->addItem(new InheritedGraphicsPolygon(scaleneTriangle));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("RANDOM:: Scalene triangle generated!",4000);
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
    ui->randomStar->setEnabled(true);
    ui->rectangle->setEnabled(true);
    ui->triangle->setEnabled(true);
    ui->other->setEnabled(true);
    ui->polygonButtonShape->setEnabled(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_ellipseButtonShape_clicked()
{
    ui->ellipseButtonShape->setEnabled(false);
    ui->randomStar->setEnabled(true);
    ui->rectangle->setEnabled(true);
    ui->triangle->setEnabled(true);
    ui->other->setEnabled(true);
    ui->polygonButtonShape->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(1);
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
    //this will be for path with holes inside
    //    QPainterPath path,path2;
    //    path2.addEllipse(QRectF(x_pos+50,y_pos+50,100,100));
    //    path.addEllipse(QRectF(x_pos,y_pos,200,200));
    //    path=path.subtracted(path2);
    //    path.setFillRule(Qt::FillRule::OddEvenFill);
    //    scene->addPath(path,QPen(),QBrush(Qt::cyan,Qt::BrushStyle::SolidPattern));

    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

}

void MainWindow::on_clearButton_clicked()
{
    scene->clear();
    scene->setSceneRect(QRectF(-300,-300,700,500));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
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
    scene->setSceneRect(scene->itemsBoundingRect());
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}


void MainWindow::on_clearPolygonData_clicked()
{
    ui->polygonVerticesEdit->clear();
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


//add a star to the scene //-----------------------
void MainWindow::on_addRandomPolygon_2_clicked()
{
    //name for this slot it is a garbage.
    //it was kept because of sort of bug
    //after a widget was deleted from mainwindow.ui
    // the [moc file] still keep the slot name for that component
    //I decided to keep the name for this slot as is
    //just to prevent a bug with moc file

    //the code from this slot( function)
    //add a star to the scene

    float x,y,longRadius,shortRadius,xOrigin,yOrigin;
    float angleValue,angleStep;
    int verticesNumber;
    //generate radius of circumscribed circle
    longRadius=QRandomGenerator::global()->bounded(60,121);
    verticesNumber=ui->verticesStarSlider->value();
    angleStep=360.0/(((float)verticesNumber)*2.0);

    //generte short radius properly
    //---------------------------------------
    float xSample1,ySample1,xSample2,ySample2;
    xSample1=longRadius*qCos(qDegreesToRadians(0));
    ySample1=longRadius*qSin(qDegreesToRadians(0));
    xSample2=longRadius*qCos(qDegreesToRadians(2*angleStep));
    ySample2=longRadius*qSin(qDegreesToRadians(2*angleStep));

    //calculate distance from a point to the line (shortRadius)
    //the line is determined through points P1(xSample1,ySample1) and P2(xSample2,ySample2)
    //distance from P1 to P2
    float distanceSample=qSqrt(qPow(xSample2-xSample1,2)+qPow(ySample2-ySample1,2));
    shortRadius=qFabs((xSample2-xSample1)*ySample1-(ySample2-ySample1)*xSample1);
    shortRadius=shortRadius/distanceSample;
    shortRadius=shortRadius*((100-ui->depthStarSlider->value())/100.0);
    //---------------------------------------
    //generate random center coordinates
    QPolygonF polygon;
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);
    for(int i=0;i<2*verticesNumber;i++)
    {
        angleValue=i*angleStep;
        if(i%2==0)
        {
            x=longRadius*qCos(qDegreesToRadians(angleValue));
            y=longRadius*qSin(qDegreesToRadians(angleValue));
        }
        else
        {
            x=shortRadius*qCos(qDegreesToRadians(angleValue));
            y=shortRadius*qSin(qDegreesToRadians(angleValue));
        }
        polygon.append(QPointF(xOrigin+x,yOrigin+y));
    }
    scene->addItem(new InheritedGraphicsPolygon(polygon));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("Star polygon generated!",4000);


}


void MainWindow::on_close_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_randomStar_clicked()
{
    ui->ellipseButtonShape->setEnabled(true);
    ui->randomStar->setEnabled(false);
    ui->rectangle->setEnabled(true);
    ui->triangle->setEnabled(true);
    ui->other->setEnabled(true);
    ui->polygonButtonShape->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(2);
}


void MainWindow::on_triangle_clicked()
{
    ui->ellipseButtonShape->setEnabled(true);
    ui->randomStar->setEnabled(true);
    ui->rectangle->setEnabled(true);
    ui->triangle->setEnabled(false);
    ui->other->setEnabled(true);
    ui->polygonButtonShape->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(3);
}


void MainWindow::on_rectangle_clicked()
{
    ui->ellipseButtonShape->setEnabled(true);
    ui->randomStar->setEnabled(true);
    ui->rectangle->setEnabled(false);
    ui->triangle->setEnabled(true);
    ui->other->setEnabled(true);
    ui->polygonButtonShape->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(4);
}


void MainWindow::on_other_clicked()
{
    ui->ellipseButtonShape->setEnabled(true);
    ui->randomStar->setEnabled(true);
    ui->rectangle->setEnabled(true);
    ui->triangle->setEnabled(true);
    ui->other->setEnabled(false);
    ui->polygonButtonShape->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_depthStarSlider_valueChanged(int value)
{
    ui->lineEditDepth->setText(QString::number(value)+" %");
}


void MainWindow::on_verticesStarSlider_valueChanged(int value)
{
    ui->lineEditVertices->setText(QString::number(value));
}

//when this button is clicked a certain triangle
//based on user selection will be drawn
void MainWindow::on_appedTriangle_clicked()
{
    switch (triangle_type) {
    case MyTriangleType::Custom :
        drawCustomTriangle();
        break;
    case MyTriangleType::Equilateral :
        drawEquilateralTriangle();
        break;
    case MyTriangleType::Isosceles :
        drawIsocscelesTriangle();
        break;
    case MyTriangleType::Scalene :
        drawScaleneTriangle();
        break;

    }
}


void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_help_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_aboutQt_clicked()
{
    QApplication::aboutQt();
}


void MainWindow::on_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//When RadioButton for custom triangle is clicked
void MainWindow::on_radioButton_4_clicked()
{
    triangle_type=MyTriangleType::Custom;
}

//When RadioButton for equilateral triangle is clicked
void MainWindow::on_radioButton_3_clicked()
{
    triangle_type=MyTriangleType::Equilateral;
}

//When RadioButton for isosceles triangle is clicked
void MainWindow::on_radioButton_2_clicked()
{
    triangle_type=MyTriangleType::Isosceles;
}


//when RadioButton for scalene triangle is clicked
void MainWindow::on_radioButton_clicked()
{
    triangle_type=MyTriangleType::Scalene;
}


void MainWindow::on_addRectangle_clicked()
{
    float xOrigin,yOrigin,width,height,rotationAngle;
    QString strWidth,strHeight,strX,strY;
    bool ok;
    strX=ui->xRectOrigin->text();
    strY=ui->yRectOrigin->text();

    if(ui->checkBoxCustomOrigin->isChecked())
    {
        //check if the user introduced data in the corresponding fields
        if(strX.isEmpty())
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("x coordinate for Origin is not specified!",4000);
            return;
        }
        if(strY.isEmpty())
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("y coordinate for Origin is not specified!",4000);
            return;
        }
        //data is extracted as string
        //now data must be checked to see if there are errors
        //if not strings will be converted to float values
        //extract Origin coordinates
        ok=false;
        xOrigin=strX.toFloat(&ok);
        if(!ok)
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("Origin x field: [ "+strX+" ] contain mistakes; not a number!",4000);
            return;
        }
        ok=false;
        yOrigin=strY.toFloat(&ok);
        if(!ok)
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("Origin y field: [ "+strY+" ] contain mistakes; not a number!",4000);
            return;
        }
    }
    else
    {
        xOrigin=QRandomGenerator::global()->bounded(-450,450);
        yOrigin=QRandomGenerator::global()->bounded(-450,450);
    }
    //checkBoxRandDim has next explanation:
    // if it is checked it means that rectangle will be created with custom dimensions
    //else it will have random dimensions
    strWidth=ui->rectWidth->text();
    strHeight=ui->rectHeight->text();
    if(ui->checkBoxRandDim->isChecked())
    {
        //check if the user introduced data in the corresponding fields
        if(strWidth.isEmpty())
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("Width is not specified!",4000);
            return;
        }
        if(strHeight.isEmpty())
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("Height is not specified!",4000);
            return;
        }
        //data is extracted as string
        //now data must be checked to see if there are errors
        //if not strings will be converted to float values
        //extract widht and height
        ok=false;
        width=strWidth.toFloat(&ok);
        if(!ok)
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("Width field: [ "+strWidth+" ] contain mistakes; not a number!",4000);
            return;
        }
        ok=false;
        height=strHeight.toFloat(&ok);
        if(!ok)
        {
            ui->statusbar->setStyleSheet("color: #AA0000;"
                                         "font: 14pt; ");
            ui->statusbar->showMessage("Height field: [ "+strHeight+" ] contain mistakes; not a number!",4000);
            return;
        }

    }
    else
    {
        width=QRandomGenerator::global()->bounded(300,500);
        height=QRandomGenerator::global()->bounded(50,250);

    }
    if(ui->checkBox->isChecked())
       rotationAngle=ui->rotationAngleSlider->value();
    else
        rotationAngle=QRandomGenerator::global()->bounded(0,360);


    //rectangle vertices
    float xA,yA,xB,yB,xC,yC,xD,yD;
    //will use an auxiliar variables to be more clear
    float x,y;
    //rotation will be done around point Origin (xOrigin,yOrigin) which is the same with A(xA,yA)
    //in conclusion point A will remain the same after rotation
    xA=xOrigin;
    yA=yOrigin;

    //the other points  will be:
    //vertex B before rotation
    xB=xOrigin+width;
    yB=yOrigin;
    //vertex B coordinates after rotation
    x=xB;
    y=yB;
    xB=(x-xOrigin)*qCos(qDegreesToRadians(rotationAngle))-(y-yOrigin)*qSin(qDegreesToRadians(rotationAngle))+xOrigin;
    yB=(x-xOrigin)*qSin(qDegreesToRadians(rotationAngle))+(y-yOrigin)*qCos(qDegreesToRadians(rotationAngle))+yOrigin;

    //vertex C before rotation
    xC=xOrigin+width;
    yC=yOrigin+height;
    //vertex C coordinates after rotation
    x=xC;
    y=yC;
    xC=(x-xOrigin)*qCos(qDegreesToRadians(rotationAngle))-(y-yOrigin)*qSin(qDegreesToRadians(rotationAngle))+xOrigin;
    yC=(x-xOrigin)*qSin(qDegreesToRadians(rotationAngle))+(y-yOrigin)*qCos(qDegreesToRadians(rotationAngle))+yOrigin;

    //vertex D before rotation
    xD=xOrigin;
    yD=yOrigin+height;
    //vertex D coordinates after rotation
    x=xD;
    y=yD;
    xD=(x-xOrigin)*qCos(qDegreesToRadians(rotationAngle))-(y-yOrigin)*qSin(qDegreesToRadians(rotationAngle))+xOrigin;
    yD=(x-xOrigin)*qSin(qDegreesToRadians(rotationAngle))+(y-yOrigin)*qCos(qDegreesToRadians(rotationAngle))+yOrigin;

    QPolygonF rectangle;
    rectangle.append(QPointF(xA,yA));
    rectangle.append(QPointF(xB,yB));
    rectangle.append(QPointF(xC,yC));
    rectangle.append(QPointF(xD,yD));

    scene->addItem(new InheritedGraphicsPolygon(rectangle));
    ui->graphicsView->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("STATUS: Rectangle generated!",6000);
}


void MainWindow::on_rotationAngleSlider_valueChanged(int value)
{
   ui->angleValueDisp->setText(QString::number(value));
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    //if arg1 is true "angle_groupBox" group box will be enabled
    //else it will be disabled
    ui->angle_groupBox->setEnabled(arg1);
    if(!arg1)
        ui->angleValueDisp->clear();
}


void MainWindow::on_checkBoxRandDim_stateChanged(int arg1)
{
    //if arg1 is true "grpBxDim" group box will be enabled
    //else it will be disabled
       ui->grpBxDim->setEnabled(arg1);
       if(!arg1)
       {
           ui->rectHeight->clear();
           ui->rectWidth->clear();
       }
}


void MainWindow::on_checkBoxCustomOrigin_stateChanged(int arg1)
{
    //if arg1 is true "grpBoxOrigin" group box will be enabled
    //else it will be disabled
    ui->grpBxOrigin->setEnabled(arg1);
    if(!arg1)
    {
        ui->xRectOrigin->clear();
        ui->yRectOrigin->clear();
    }
}


void MainWindow::on_cogsNrSlider_valueChanged(int value)
{
    ui->cogsNumberDisp->setText(QString::number(value));
}


void MainWindow::on_cogsBaseRadiusSilder_valueChanged(int value)
{
    ui->cogsBaseRadiusDisp->setText(QString::number(value));
}


void MainWindow::on_cogsHeightSlider_valueChanged(int value)
{
    ui->cogsHeightDisp->setText(QString::number(value)+" %");
}

void MainWindow::on_addCogwheel_clicked()
{
    float nrCogs,cogBaseRadius,cogHeight;
    nrCogs=ui->cogsNrSlider->value();
    cogBaseRadius=ui->cogsBaseRadiusSilder->value();
    cogHeight=ui->cogsHeightSlider->value();
    cogHeight=cogHeight*cogBaseRadius/100.0;

    float angleStep,angleValue=0;
    angleStep=360.0/nrCogs;

    float x,y,xOrigin,yOrigin,cogBigRadius;
    cogBigRadius=cogBaseRadius+cogHeight;

    //generate random center coordinates
    QPolygonF cogShape;
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);
    for(int i=0;i<nrCogs;i++)
    {
        angleValue=i*angleStep;
        x=cogBaseRadius*qCos(qDegreesToRadians(angleValue));
        y=cogBaseRadius*qSin(qDegreesToRadians(angleValue));
        cogShape.append(QPointF(xOrigin+x,yOrigin+y));
        x=cogBigRadius*qCos(qDegreesToRadians(angleValue+0.1*angleStep));
        y=cogBigRadius*qSin(qDegreesToRadians(angleValue+0.1*angleStep));
        cogShape.append(QPointF(xOrigin+x,yOrigin+y));
        x=cogBigRadius*qCos(qDegreesToRadians(angleValue+0.5*angleStep));
        y=cogBigRadius*qSin(qDegreesToRadians(angleValue+0.5*angleStep));
        cogShape.append(QPointF(xOrigin+x,yOrigin+y));
        x=cogBaseRadius*qCos(qDegreesToRadians(angleValue+0.6*angleStep));
        y=cogBaseRadius*qSin(qDegreesToRadians(angleValue+0.6*angleStep));
        cogShape.append(QPointF(xOrigin+x,yOrigin+y));
        x=cogBaseRadius*qCos(qDegreesToRadians(angleValue+angleStep));
        y=cogBaseRadius*qSin(qDegreesToRadians(angleValue+angleStep));
        cogShape.append(QPointF(xOrigin+x,yOrigin+y));
    }
    scene->addItem(new InheritedGraphicsPolygon(cogShape));
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->statusbar->setStyleSheet("color: #112090;"
                                 "font: 14pt; ");
    ui->statusbar->showMessage("STATUS:: CogWheel added!",4000);
}


void MainWindow::on_transparencySlider_valueChanged(int value)
{
    ui->opacityDisp->setText(QString::number(value)+"%");
    setWindowOpacity((float)value/100.0);
}

