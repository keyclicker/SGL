#ifndef VIEW_HPP
#define VIEW_HPP

#include <QGraphicsView>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

#include "Scene.hpp"

class View : public QGraphicsView
{
	Q_OBJECT

public:
	explicit View(QWidget *parent = nullptr);
	~View();

    void mousePressEvent(QMouseEvent *mouseEvent); //we do it in graphicsView to get correct coordinates for scene
    void mouseReleaseEvent(QMouseEvent *mouseEvent);
    void paintEvent(QPaintEvent *event) override;

public slots:
    void worldStep();

private:
    QTimer *timer;//timer for controlling fps
	Scene *scene;
};

#endif // VIEW_HPP
