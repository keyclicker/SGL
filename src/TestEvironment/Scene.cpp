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

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	//here comes kostil
	GObject *object = new GObject(mouseEvent->scenePos(), (Scene*) this);
	this->addItem(object);

	this->curObj = object->object;
	this->prevPos = mouseEvent->pos();
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	auto v = (prevPos - mouseEvent->pos()) / 5; //magic

	this->curObj->setVelocity(v.x(), v.y());

	this->world.addObject(curObj);
}
