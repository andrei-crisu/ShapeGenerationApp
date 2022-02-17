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

}

//this function draws an equilateral triangle
void MainWindow::drawEquilateralTriangle()
{

}

//this function draws an isosceles triangle
void MainWindow::drawIsocscelesTriangle()
{

}

//this function draws a scalene triangle
//(this means that the triangle sides have different lengths)
void MainWindow::drawScaleneTriangle()
{
    //the shape is a traingle (there are 3 vertices)
    int nr=3;
    float x,y,r,xOrigin,yOrigin;

    //generate radius of circumscribed circle
    r=QRandomGenerator::global()->bounded(60,121);
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
    //origin of circumscribed circle
    xOrigin=QRandomGenerator::global()->bounded(-300,301);
    yOrigin=QRandomGenerator::global()->bounded(-300,301);
    for(int i=0;i<nr;i++)
    {
        val=firstList.at(i);
        x=r*qCos(qDegreesToRadians(val));
        y=r*qSin(qDegreesToRadians(val));
        polygon.append(QPointF(xOrigin+x,yOrigin+y));
    }
    scene->addItem(new InheritedGraphicsPolygon(polygon));
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
    ui->graphicsView->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
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

    //calculate distance from a poin to the line (shortRadius)
    //the line is determined through points P1(xSample1,ySample1) and P2(xSample2,ySample2)
    //distance from P1 to P2
    float distanceSample=qSqrt(qPow(xSample2-xSample1,2)+qPow(ySample2-ySample1,2));
    shortRadius=qFabs((xSample2-xSample1)*ySample1-(ySample2-ySample1)*xSample1);
    shortRadius=shortRadius/distanceSample;
    shortRadius=shortRadius*((100-ui->depthStarSlider->value())/100.0);
    //---------------------------------------

    //just as reminder
    //---------------------------------------
    /*  generate short radius,but  not prorerly
    in some cases generated stars will be ugly
    shortRadius=longRadius*((100-ui->depthStarSlider->value())/100.0);*/
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
        qDebug()<<"Custom";
        drawCustomTriangle();
        break;
    case MyTriangleType::Equilateral :
        qDebug()<<"Equilateral";
        drawEquilateralTriangle();
        break;
    case MyTriangleType::Isosceles :
        qDebug()<<"Isosceles";
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

