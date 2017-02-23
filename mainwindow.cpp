#include "mainwindow.h"
#include "ui_mainwindow.h"

bool setline = false;
bool setselect = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRectF rectscene = ui->view->sceneRect();
    scene = new Scene(this);
    scene->setSceneRect(rectscene);
    ui->view->setScene(scene);
    ui->view->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);


    QGraphicsRectItem* itr = new QGraphicsRectItem();
    itr->setRect(20,20,100,100);
    QGraphicsRectItem* itr1 = new QGraphicsRectItem();
    itr1->setRect(20,80,100,100);
    scene->addItem(itr);
    scene->addItem(itr1);

    connect(ui->pline, SIGNAL(toggled(bool)), this, SLOT(line(bool)));
    connect(ui->pselect, SIGNAL(toggled(bool)), this, SLOT(select(bool)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::line(bool l)
{
    if(l)
    {
        setline = true;
        setselect = false;
        scene->setMode(Scene::DrawLine);
    }

}

void MainWindow::select(bool s)
{
    if(s)
    {
        setline = false;
        setselect = true;
        scene->setMode(Scene::SelectObject);
    }


}




