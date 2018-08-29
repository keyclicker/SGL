#include "World.hpp"


std::vector<ptr<Object>> World::getObjects() const
{
	return Objects;
}

void World::addObject(Object &value)
{
	Objects.push_back(ptr<Object>(&value));
}

void World::createObject(const Vector position, const double mass)
{
	Objects.push_back(ptr<Object>(new Object(position, mass)));
}

void World::step(double time)
{
	for (auto &obj1 : Objects)
	{
		for (auto &obj2 : Objects)
		{
			if (obj1 == obj2) continue; // fordebug

			auto direction = (*obj2).getPosition() - (*obj1).getPosition();
			auto R = direction.length();

			direction = direction / R;

			auto gravityForce = direction * World::getG() *
					(((*obj1).getMass() * (*obj2).getMass()) / (R*R));

			(*obj1).applyForce(gravityForce, time);
		}
		(*obj1).step(time);
	}
}
