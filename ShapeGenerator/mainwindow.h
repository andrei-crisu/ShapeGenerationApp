#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"customscene.h"
#include<QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


enum class MyTriangleType{Scalene,Isosceles,Equilateral,Custom};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void resizeEvent(QResizeEvent *event)override;
    void closeEvent(QCloseEvent *event)override;
    void drawCustomTriangle();
    void drawEquilateralTriangle();
    void drawIsocscelesTriangle();
    void drawScaleneTriangle();

private:
    Ui::MainWindow *ui;
    CustomScene *scene;
    MyTriangleType triangle_type=MyTriangleType::Custom;

signals:
    void sentMessage(const QString string);
public slots:
    void onTimer();
    void showMessage(QString string);

private slots:
    void on_splitter_splitterMoved(int pos, int index);
    void on_polygonButtonShape_clicked();
    void on_ellipseButtonShape_clicked();
    void on_clearEllipseData_clicked();
    void on_addEllipse_clicked();
    void on_clearButton_clicked();
    void on_zoomInButtton_clicked();
    void on_zoomOutButton_clicked();
    void on_zoomToFitButton_clicked();
    void on_clearPolygonData_clicked();
    void on_addPolygon_clicked();
    void on_addRandomPolygon_clicked();
    void on_addRandomIrregularPolygon_clicked();
    void on_addRandomPolygon_2_clicked();
    void on_shapeDrawing_clicked();
    void on_close_clicked();
    void on_randomStar_clicked();
    void on_triangle_clicked();
    void on_rectangle_clicked();
    void on_other_clicked();
    void on_depthStarSlider_valueChanged(int value);
    void on_verticesStarSlider_valueChanged(int value);
    void on_appedTriangle_clicked();
    void on_home_clicked();
    void on_help_clicked();
    void on_aboutQt_clicked();
    void on_home_2_clicked();
    void on_settings_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_addRectangle_clicked();
    void on_rotationAngleSlider_valueChanged(int value);
    void on_checkBox_stateChanged(int arg1);
    void on_checkBoxRandDim_stateChanged(int arg1);
    void on_checkBoxCustomOrigin_stateChanged(int arg1);
    void on_cogsNrSlider_valueChanged(int value);
    void on_cogsBaseRadiusSilder_valueChanged(int value);
    void on_cogsHeightSlider_valueChanged(int value);
    void on_addCogwheel_clicked();
    void on_transparencySlider_valueChanged(int value);
};
#endif // MAINWINDOW_H
