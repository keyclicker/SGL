#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <memory>
#include "Object.hpp"

namespace sgl
{

using ObjPtr = std::shared_ptr<Object>;

class World
{
private:
	std::vector<ObjPtr> objects;
	double G = 0.0000000000667384; //Default G const

public:
	World() {}

	World(const World &value) = delete;
	World operator=(const World &value) = delete;

	double getG() const;
	void setG(double value);

	std::vector<ObjPtr> getObjects() const;
	void addObject(Object &value);
	void addObject(Object *value);
	void createObject(const Vector &position, double mass);

	void step(double time);
};

}

#endif // WORLD_HPP
