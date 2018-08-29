#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <memory>
#include "Object.hpp"

template<typename T>
using ptr = std::shared_ptr<T>;

class World
{
private:
	std::vector<ptr<Object>> Objects;

public:
	World() {}

	World(const World &value) = delete;
	World operator=(const World &value) = delete;

	std::vector<ptr<Object>> getObjects() const;
	void addObject(Object &value);
	void createObject(const Vector position, const double mass);

	void step(double time);

	static double getG()
	{
		static double G = 0.0000000000667384;
		return G;
	}
};

#endif // WORLD_HPP
