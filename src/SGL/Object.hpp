#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vector.hpp"

namespace sgl
{

class Object
{
private:
	Vector position;
	Vector velocity;
	double mass;
	bool IsStatic = false;

public:
	Object() {}

	Object(const Vector &position, const Vector &velocity, const double mass) :
		position(position), velocity(velocity), mass(mass) {}

	Object(const Vector &position, const double mass) :
		position(position), mass(mass) {}

	Object(const double mass) : mass(mass) {}

	virtual ~Object() {}

	bool isStatic() const;
	void setStatic(const bool val);

	double getMass() const;
	void setMass(const double value);

	Vector getPosition() const;
	void setPosition(const Vector &value);
	void setPosition(const double x, const double y);

	Vector getVelocity() const;
	void setVelocity(const Vector &value);
	void setVelocity(const double x, const double y);

	void move(const Vector &value);

	void applyForce(const Vector &force, const double time);
	void applyForce(const double forceX, const double forceY, const double time);

	void step(const double time);

};

}

#endif // OBJECT_HPP
