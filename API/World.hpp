#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <memory>
#include "Object.hpp"

using ObjPtr = std::shared_ptr<Object>;

class World
{
private:
	std::vector<ObjPtr> Objects;

public:
	World() {}

	World(const World &value) = delete;
	World operator=(const World &value) = delete;

	std::vector<ObjPtr> getObjects() const;
	void addObject(Object &value);
	void createObject(const Vector &position, const double mass);

	void step(const double time);

	static double getG()
	{
		static double G = 0.0000000000667384;
		return G;
	}
};

#endif // WORLD_HPP
