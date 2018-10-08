#include "Object.hpp"

namespace sgl
{

bool Object::isStatic() const
{
	return static_;
}

void Object::setStatic(bool val)
{
	static_ = val;
}

double Object::getMass() const
{
	return mass;
}

void Object::setMass(double value)
{
	mass = value;
}

Vector Object::getPosition() const
{
	return position;
}

void Object::setPosition(const Vector &value)
{
	position = value;
}

void Object::setPosition(double x, double y)
{
	setPosition(Vector(x, y));
}

Vector Object::getVelocity() const
{
	return velocity;
}

void Object::setVelocity(const Vector &value)
{
	velocity = value;
}

void Object::setVelocity(double x, double y)
{
	setVelocity(Vector(x, y));
}

void Object::move(const Vector &value)
{
	position = position + value;
}

void Object::applyForce(const Vector &force, double time)
{
	velocity = velocity + (force / mass) * time;
}

void Object::applyForce(double forceX, double forceY, double time)
{
	applyForce(Vector(forceX, forceY), time);
}

void Object::step(double time)
{
	if (!static_)
	{
		move(velocity * time);
	}
}

}
