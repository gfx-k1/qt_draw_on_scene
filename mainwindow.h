#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QToolBar>
#include "scene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void select(bool s);
    void line(bool l);

private:
    Ui::MainWindow *ui;
    QGraphicsView* view;
    Scene* scene;


};

#endif // MAINWINDOW_H
