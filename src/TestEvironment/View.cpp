#include "View.hpp"

View::View(QWidget *parent) :
	  QGraphicsView(parent)
{
    scene = new Scene(this);
    scene->setSceneRect(0,0,1000,1000); //necessary to have stable coordinates
    this->setScene(scene);

    timer=new QTimer(this);  //timer for controlling fps
    connect(timer,SIGNAL(timeout()),this,SLOT(worldStep()));     //when timer emit timeout, we make world step. So that we have stable intervals between world steps
    timer->setInterval(5);  //controlling fps(now we have 20 frames per second)
    timer->start(5);
}

View::~View()
{

}

void View::mousePressEvent(QMouseEvent *mouseEvent)
{
    //kostil is probably fixed
    QPointF clickPoint=mapToScene(mouseEvent->pos());  //get correct coords of click regarding to graphicsScene

    qDebug()<<"Mouse pressed "<<mouseEvent->pos().x()<<" "<<mouseEvent->pos().y();   //where we pressed regarding to graphicsView
    qDebug()<<"Map to scene: "<<clickPoint.x()<<" "<<clickPoint.y();                 //where we pressed regarding to graphicsScene

    scene->createObject(clickPoint);                                                 //create GObject in clickpoint coords
}

void View::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    QPointF clickPoint=mapToScene(mouseEvent->pos()); //get correct coords of click regarding to graphicsScene

    scene->setObjectSpeed(clickPoint);  //set starting speed for our object

}

void View::paintEvent(QPaintEvent *event)
{
	QGraphicsView::paintEvent(event);
}

void View::worldStep()   //here we do worldStep
{
    scene->world.step(5000);
    scene->update();       //update scene to repaint GObjects
    qDebug()<<"World step";
}
