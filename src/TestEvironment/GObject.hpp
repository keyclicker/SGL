#ifndef GOBJECT_HPP
#define GOBJECT_HPP

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>
#include <QDebug>

#include "SGL/Gravity.hpp"

class Scene;

class GObject : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

public:
	explicit GObject(QPointF point, QObject *parent = nullptr);
	~GObject();

	void paint(QPainter *painter,
			   const QStyleOptionGraphicsItem *option,
			   QWidget *widget = nullptr) override;

	sgl::Object *object;
};

#endif // GOBJECT_HPP
