#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"customscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void resizeEvent(QResizeEvent *event)override;
    void closeEvent(QCloseEvent *event)override;

private:
    Ui::MainWindow *ui;
    CustomScene *scene;

signals:
    void sentMessage(const QString string);
public slots:
    void onTimer();
    void showMessage(QString string);

private slots:
    void on_splitter_splitterMoved(int pos, int index);
    void on_polygonButton_clicked();
    void on_ellipseButton_clicked();
    void on_clearEllipseData_clicked();
    void on_addEllipse_clicked();
    void on_clearButton_clicked();
    void on_zoomInButtton_clicked();
    void on_zoomOutButton_clicked();
    void on_zoomToFitButton_clicked();
    void on_clearPolygonData_clicked();
    void on_addPolygon_clicked();
    void on_addRandomPolygon_clicked();
};
#endif // MAINWINDOW_H
