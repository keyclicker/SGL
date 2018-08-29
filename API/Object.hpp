#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vector.hpp"

class Object
{
private:
	Vector position;
	Vector velocity;
	double mass;

public:
	Object() {}

	Object(Vector position, Vector velocity, double mass) :
		position(position), velocity(velocity), mass(mass) {}

	Object(Vector position, double mass) :
		position(position), mass(mass) {}

	Object(double mass) : mass(mass) {}

	virtual ~Object() {}


	double getMass() const;
	void setMass(double value);

	Vector getPosition() const;
	void setPosition(const Vector &value);

	Vector getVelocity() const;
	void setVelocity(const Vector &value);

	void move(const Vector &value);

	void applyForce(const Vector &force, const double time);
	void applyForce(const double forceX, const double forceY, const double time);

	void step(double time);

};

#endif // OBJECT_HPP
