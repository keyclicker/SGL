#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

#include "Scene.hpp"
#include "View.hpp"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = nullptr);
	~Widget();

private:
	Ui::Widget *ui;
};

#endif // WIDGET_HPP
