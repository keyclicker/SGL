#include "Object.hpp"


bool Object::isStatic() const
{
	return IsStatic;
}

void Object::setStatic(const bool val)
{
	IsStatic = val;
}

double Object::getMass() const
{
	return mass;
}

void Object::setMass(const double value)
{
	mass = value;
}

Vector Object::getPosition() const
{
	return position;
}

void Object::setPosition(const Vector &value)
{
	if (!IsStatic)
	{
		position = value;
	}
}

Vector Object::getVelocity() const
{
	return velocity;
}

void Object::setVelocity(const Vector &value)
{
	velocity = value;
}

void Object::move(const Vector &value)
{
	if (!IsStatic)
	{
		position = position + value;
	}
}

void Object::applyForce(const Vector &force, const double time)
{
	velocity = velocity + (force / mass) * time;
}

void Object::applyForce(const double forceX, const double forceY, const double time)
{
	applyForce(Vector(forceX, forceY), time);
}

void Object::step(const double time)
{
	move(velocity * time);
}
