#include "GObject.hpp"

GObject::GObject(QPointF point, QObject *parent):
	QObject(parent), QGraphicsEllipseItem(point.x()-10, point.y()-10, 20, 20)
{
	object = new sgl::Object(200);
	object->setPosition(point.x(), point.y());

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(QColor(200, 200, 200));

	this->setBrush(brush);
}

GObject::~GObject()
{
	delete object;
}

void GObject::paint(QPainter *painter,
	const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	this->setX(this->object->getPosition().x);
	this->setY(this->object->getPosition().y);

	QGraphicsEllipseItem::paint(painter, option, widget);
}
