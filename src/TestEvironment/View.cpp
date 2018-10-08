#include "View.hpp"

View::View(QWidget *parent) :
	  QGraphicsView(parent)
{
	scene = new Scene(this);

	this->setScene(scene);
}

View::~View()
{

}

void View::paintEvent(QPaintEvent *event)
{
	QGraphicsView::paintEvent(event);

	this->scene->world.step(50000); //magic constant
}
