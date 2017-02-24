#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QToolBar>
#include "scene.h"
#include <QAction>

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
    void line();
    void cancel();
    void selection();
    void rect1();
    void rect2();

private:
    Ui::MainWindow *ui;
    QGraphicsView* gView;
    Scene* scene;
    QGraphicsRectItem* itr1;
    QGraphicsRectItem* itr2;
};

#endif // MAINWINDOW_H
