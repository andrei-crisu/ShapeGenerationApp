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
public slots:
    void onTimer();

private slots:
    void on_splitter_splitterMoved(int pos, int index);
    void on_polygonButton_clicked();
    void on_ellipseButton_clicked();
};
#endif // MAINWINDOW_H
