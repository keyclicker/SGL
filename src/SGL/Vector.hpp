#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

namespace sgl
{

class Vector
{
public:
	double x, y;

	explicit Vector(const double x = 0, const double y = 0) : x(x), y(y) {}
	~Vector() {}

	double length()
	{
		return hypot(x, y);
	}

	Vector operator+(const Vector &value) const
	{
		return Vector(x + value.x, y + value.y);
	}

	Vector operator-(const Vector &value) const
	{
		return Vector(x - value.x, y - value.y);
	}

	Vector operator/(const double value) const
	{
		return Vector(x / value, y / value);
	}

	Vector operator*(const double value) const
	{
		return Vector(x * value, y * value);
	}
};

}

#endif // VECTOR_HPP


