#include "Scene.hpp"

#include <QDebug>


Scene::Scene(QObject *parent) :
			 QGraphicsScene(parent)
{
	QBrush brush;
	brush.setColor(QColor(50, 50, 50));
	brush.setStyle(Qt::SolidPattern);
	this->setBackgroundBrush(brush);
}

Scene::~Scene()
{

}

void Scene::createObject(QPointF initCords)
{
    GObject *object = new GObject(initCords, (Scene*) this); //create object and place it to our initCords
    this->addItem(object);

    this->curObj = object->object;
    this->prevPos = initCords;
}

void Scene::setObjectSpeed(QPointF releaseCords)
{
    auto v = (prevPos - releaseCords) / startingSpeedKoef;

    qDebug()<<"Mouse released "<<v.x()<<" "<<v.y();

    this->curObj->setVelocity(v.x(), v.y());

    this->world.addObject(curObj);
}
