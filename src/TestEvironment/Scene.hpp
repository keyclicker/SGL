#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "QBrush"
#include "GObject.hpp"

class Scene : public QGraphicsScene
{
	Q_OBJECT

public:
	explicit Scene(QObject *parent = nullptr);
	~Scene();

	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

	sgl::World world;

private:
	QPointF prevPos;
	sgl::Object *curObj;
};

#endif // SCENE_HPP
