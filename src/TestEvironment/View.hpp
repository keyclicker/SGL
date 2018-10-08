#ifndef VIEW_HPP
#define VIEW_HPP

#include <QGraphicsView>

#include "Scene.hpp"

class View : public QGraphicsView
{
	Q_OBJECT

public:
	explicit View(QWidget *parent = nullptr);
	~View();

	void paintEvent(QPaintEvent *event) override;

private:
	Scene *scene;
};

#endif // VIEW_HPP
