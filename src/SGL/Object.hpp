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
	bool static_ = false;

    const double maxSpeed=0.3; //speed limiter,needs to be changed

	void step(const double time);

public:
	friend class World;

	Object() {}

	Object(const Vector &position, const Vector &velocity, double mass) :
		position(position), velocity(velocity), mass(mass) {}

	Object(const Vector &position, double mass) :
		position(position), mass(mass) {}

	Object(double mass) : mass(mass) {}

	virtual ~Object() {}

	bool isStatic() const;
	void setStatic(bool val);

	double getMass() const;
	void setMass(double value);

	Vector getPosition() const;
	void setPosition(const Vector &value);
	void setPosition(double x, double y);

	Vector getVelocity() const;
	void setVelocity(const Vector &value);
	void setVelocity(double x, double y);

	void move(const Vector &value);

	void applyForce(const Vector &force, double time);
	void applyForce(double forceX, double forceY, double time);
};

}

#endif // OBJECT_HPP
