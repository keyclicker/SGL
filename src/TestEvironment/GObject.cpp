#include "GObject.hpp"

GObject::GObject(QPointF point, QObject *parent):
    QObject(parent), QGraphicsEllipseItem(0, 0, 20, 20) //rect of the object
{
	object = new sgl::Object(200);
    object->setPosition(point.x()-10,point.y()-10); //we substract 10 to place center of cirlce in point coords
    setPos(point.x()-10,point.y()-10);

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
    qDebug()<<"Repaint GObject";
    this->setPos(this->object->getPosition().x,this->object->getPosition().y);

	QGraphicsEllipseItem::paint(painter, option, widget);
}
