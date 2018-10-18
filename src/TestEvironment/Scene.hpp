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

    void createObject(QPointF initCords);
    void setObjectSpeed(QPointF releaseCords);

	sgl::World world;

private:
    const int startingSpeedKoef=500000;
	QPointF prevPos;
	sgl::Object *curObj;
};

#endif // SCENE_HPP
