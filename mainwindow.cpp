#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    QRectF tr = ui->gView->sceneRect();
    scene->setSceneRect(tr);
    ui->gView->setScene(scene);
    ui->gView->setRenderHint(QPainter::Antialiasing);
    QGraphicsRectItem* itr = new QGraphicsRectItem();
    itr->setRect(20,20,100,100);
    itr->setZValue(10);
    itr1 = new QGraphicsRectItem();
    itr2 = new QGraphicsRectItem();
    itr1->setRect(20,80,100,100);
    itr1->setZValue(100);
    scene->addItem(itr);
    scene->addItem(itr1);

    rect1();
    rect2();





    connect(ui->line, SIGNAL(pressed()), this, SLOT(line()));
    connect(ui->selection, SIGNAL(pressed()), this, SLOT(selection()));
    connect(ui->cancel, SIGNAL(pressed()), this, SLOT(cancel()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selection()
{
    scene->setMode(Scene::SelectObject);
}

void MainWindow::line()
{
     scene->setMode(Scene::DrawLine);
}

void MainWindow::cancel()
{
    QList<QGraphicsItem* > item = scene->items();
    for(int e = 0; e < item.size(); e++)
    {
        if((item[e]->zValue() > 45) && (item[e]->zValue() < 55))
        {
            scene->removeItem(item[e]);
        }

    }
}

void MainWindow::rect1()
{
    for ( int i = 0; i<30; i++)
    {
        //QGraphicsRectItem* itr2 = new QGraphicsRectItem();

        itr2 = scene->addRect((5*i),(6*i),30,30);
        itr2->setRect((5*i),(6*i),30,30);
        itr2->setZValue(50);
        //scene->addItem(itr2);
    }
}

void MainWindow::rect2()
{
    QGraphicsRectItem* itra = new QGraphicsRectItem();
    itra->setRect(-50,30,100,100);
    itra->setZValue(100);
    QGraphicsRectItem* itra1 = new QGraphicsRectItem();
    itra1->setRect(-100,400,100,100);
    itra1->setZValue(100);
    scene->addItem(itra);
    scene->addItem(itra1);
}
